<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function kendra_api_schema_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
}

/**
 * Implementation of hook_node_info().
 */
function kendra_api_schema_node_info() {
  $items = array(
    'attribute' => array(
      'name' => t('Attribute'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Attribute label'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'container' => array(
      'name' => t('Container'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
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
function kendra_api_schema_views_api() {
  return array(
    'api' => '2',
  );
}
