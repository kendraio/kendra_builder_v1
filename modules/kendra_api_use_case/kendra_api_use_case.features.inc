<?php

/**
 * Implementation of hook_node_info().
 */
function kendra_api_use_case_node_info() {
  $items = array(
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
