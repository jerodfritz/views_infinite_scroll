<?php

/**
 * Implementation of hook_views_plugins()
 */
function views_infinite_scroll_views_plugins() {
  return array(
    'pager' => array(
      'parent' => array(
        'no ui' => TRUE,
        'handler' => 'views_plugin_pager',
        'parent' => '',
      ),
      'infinite_scroll' => array(
        'title' => t('Paged output, infinite scroll'),
        'help' => t('Use the infinite scroll JQuery Plugin.'),
        'handler' => 'views_plugin_pager_infinite_scroll',
        'help topic' => 'pager-infinite-scroll',
        'uses options' => TRUE,
        'parent' => 'full',
      ),
    ),
  );
}

