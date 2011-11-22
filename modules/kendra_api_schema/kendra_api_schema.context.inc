<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function kendra_api_schema_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'attributes';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'attribute' => 'attribute',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-attribute_type-block_1' => array(
          'module' => 'views',
          'delta' => 'attribute_type-block_1',
          'region' => 'content',
          'weight' => 0,
        ),
        'views-attribute_links-block_1' => array(
          'module' => 'views',
          'delta' => 'attribute_links-block_1',
          'region' => 'content',
          'weight' => 1,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['attributes'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'container';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'container' => 'container',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-container_attributes-block_1' => array(
          'module' => 'views',
          'delta' => 'container_attributes-block_1',
          'region' => 'content',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['container'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'global';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-current_node_type-block_1' => array(
          'module' => 'views',
          'delta' => 'current_node_type-block_1',
          'region' => 'header',
          'weight' => 0,
        ),
        'menu-secondary-links' => array(
          'module' => 'menu',
          'delta' => 'secondary-links',
          'region' => 'footer',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['global'] = $context;

  return $export;
}
