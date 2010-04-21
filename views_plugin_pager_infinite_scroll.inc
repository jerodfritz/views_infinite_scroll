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
    $pager_theme = views_theme_functions('views_infinite_scroll_pager', $this->view, $this->display);
    return theme($pager_theme, $input, $this->options['items_per_page'], $this->options['id']);
  }
}
