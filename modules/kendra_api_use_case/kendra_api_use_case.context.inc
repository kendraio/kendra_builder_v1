<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function kendra_api_use_case_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'requirements';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'requirements' => 'requirements',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-subtask_view-block_1' => array(
          'module' => 'views',
          'delta' => 'subtask_view-block_1',
          'region' => 'content',
          'weight' => 0,
        ),
        'views-usecase_view-block_1' => array(
          'module' => 'views',
          'delta' => 'usecase_view-block_1',
          'region' => 'content',
          'weight' => 1,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['requirements'] = $context;

  return $export;
}
