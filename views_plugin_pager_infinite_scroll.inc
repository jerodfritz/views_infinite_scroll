<?php
// $Id: views_plugin_pager_infinite_scroll.inc

/**
 * The plugin to handle an infinite scroll pager.
 * 
 * @ingroup views_pager_plugins
 */
class views_plugin_pager_infinite_scroll extends views_plugin_pager_full {
  function summary_title() {
    if (!empty($this->options['offset'])) {
      return format_plural($this->options['items_per_page'], 'Infinite Scroll pager, @count item, skip @skip', 'Infinite Scroll pager, @count items, skip @skip', array('@count' => $this->options['items_per_page'], '@skip' => $this->options['offset']));
    }
      return format_plural($this->options['items_per_page'], 'Infinite Scroll pager, @count item', 'Infinite Scroll pager, @count items', array('@count' => $this->options['items_per_page']));
  }

  function render($input) {

    $style_plugin = $this->view->display_handler->default_display->options['style_plugin'];
    $style_options = $this->view->display_handler->default_display->options['style_options'];
    $row_plugin = $this->view->display_handler->default_display->options['row_plugin'];


    $target = '';
    $itemselector = '';
    
    switch($style_plugin){
      case 'default':
        $target = 'div.view-content';
        $itemselector = 'div.view-content .views-row';
        break;
      case 'grid':
        $target = 'div.view-content tbody';
        $itemselector = 'div.view-content tbody tr';
        break;
      case 'list':
        $target = 'div.view-content .item-list:first-child';
        $itemselector = 'div.view-content .views-row';
        break;
      case 'table':
        $target = 'div.view-content tbody';
        $itemselector = 'div.view-content tbody tr';
        break;
    }
        
    $pager_theme = views_theme_functions('views_infinite_scroll_pager', $this->view, $this->display);
    return theme($pager_theme, $input, $this->options['items_per_page'], $this->options['id'], $this->options['automatic'], $this->options['loadingtext'], $this->options['donetext'], $this->options['moretext'], $target, $itemselector);
  }

  /**
   * Set default options
   */
  function option_definition() {
    $options = parent::option_definition();
    unset($options['expose']); // remove full pager inherited expose options

    $options['automatic'] = array('default' => false);
    $options['loadingtext'] = array('default' => t('Loading next page...')); 
    $options['donetext'] = array('default' => t('You\'ve reached the last page')); 
    $options['moretext'] = array('default' => t('Show More')); 
    return $options;
  }

  /**
   * Render the given style.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    watchdog(WATCHDOG_DEBUG, __FILE .': '. __LINE__);

  
    $form['type']['#description'] = t('Whether to present the user with a more button to click or automatically load the next page when you reach the end of the page.');

    unset($form['expose']); // remove full pager inherited expose options

    $form['automatic'] = array(
      '#type' => 'select',
      '#title' => t('Loading of Content'),
      '#options' => array(
         false => t('Manual'),
         true => t('Automatic'),
        ),
      '#default_value' => $this->options['automatic'],
      '#description' => t('Select Manual to present the user with a more button to manually load the next page or Automatic to have this triggered by a more button.'),
    );

    $form['loadingtext'] = array(
      '#type' => 'textfield',
      '#title' => t('Loading Text'),
      '#size' => 255,
      '#maxlength' => 255,
      '#default_value' => $this->options['loadingtext'],
      '#description' => t('The text presented to the user while the next page is being loaded.'),
    );    

    $form['donetext'] = array(
      '#type' => 'textfield',
      '#title' => t('Done Text'),
      '#size' => 255,
      '#maxlength' => 255,
      '#default_value' => $this->options['donetext'],
      '#description' => t('The text presented to the user when there are no more pages to load'),

    );    
    $form['moretext'] = array(
      '#type' => 'textfield',
      '#title' => t('More Text'),
      '#size' => 255,
      '#maxlength' => 255,
      '#default_value' => $this->options['moretext'],
      '#description' => t('If you have selected Manual operation this is the link the user will click to go to the next page'),

    );
  }

  function options_validate(&$form, &$form_state) {
    //assume input values are correct
  }

}
