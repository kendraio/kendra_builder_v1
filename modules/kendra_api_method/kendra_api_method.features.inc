<?php

/**
 * Implementation of hook_node_info().
 */
function kendra_api_method_node_info() {
  $items = array(
    'method' => array(
      'name' => t('Method'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Method name'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function kendra_api_method_views_api() {
  return array(
    'api' => '2',
  );
}
