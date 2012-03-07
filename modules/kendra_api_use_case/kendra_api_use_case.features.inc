<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function kendra_api_use_case_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
}

/**
 * Implementation of hook_node_info().
 */
function kendra_api_use_case_node_info() {
  $items = array(
    'action' => array(
      'name' => t('Action'),
      'module' => 'features',
      'description' => t('A single step or atomic activity within a Use Case'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'requirements' => array(
      'name' => t('Requirements'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Expected result'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'use_case' => array(
      'name' => t('Use case'),
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
function kendra_api_use_case_views_api() {
    drupal_add_js(drupal_get_path('module', 'kendra_api_use_case') .'/kendra_api_use_case.js');
    drupal_add_css(drupal_get_path('module', 'kendra_api_use_case') .'/kendra_api_use_case.css');

  return array(
    'api' => '2',
  );
}
