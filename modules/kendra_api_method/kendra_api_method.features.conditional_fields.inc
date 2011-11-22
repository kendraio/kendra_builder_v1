<?php

/**
 * Implementation of hook_conditional_fields_default_fields().
 */
function kendra_api_method_conditional_fields_default_fields() {
$items = array();
$items[] = array (
  'control_field_name' => 'field_rest_http_method',
  'field_name' => 'field_rest_request_payload',
  'type' => 'method',
  'trigger_values' => 
  array (
    'POST' => 'POST',
    'PUT' => 'PUT',
  ),
);
$items[] = array (
  'control_field_name' => 'field_rest_http_method',
  'field_name' => 'field_method_return',
  'type' => 'method',
  'trigger_values' => 
  array (
    'GET' => 'GET',
    'POST' => 'POST',
    'PUT' => 'PUT',
  ),
);
return $items;
}
