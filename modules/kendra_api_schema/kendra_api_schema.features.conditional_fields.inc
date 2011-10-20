<?php

/**
 * Implementation of hook_conditional_fields_default_fields().
 */
function kendra_api_schema_conditional_fields_default_fields() {
$items = array();
$items[] = array (
  'control_field_name' => 'field_container_base',
  'field_name' => 'field_container_attribute',
  'type' => 'container',
  'trigger_values' => 
  array (
    2 => '2',
  ),
);
return $items;
}
