<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function kendra_api_method_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_request
  $groups['method-group_request'] = array(
    'group_type' => 'standard',
    'type_name' => 'method',
    'group_name' => 'group_request',
    'label' => 'Request',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '-2',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'description' => '',
        '5' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '-2',
    'fields' => array(
      '0' => 'field_rest_http_method',
      '1' => 'field_rest_uri_fragment',
      '2' => 'field_rest_request_payload',
      '3' => 'field_rpc_method',
      '4' => 'field_method_params',
    ),
  );

  // Exported group: group_response
  $groups['method-group_response'] = array(
    'group_type' => 'standard',
    'type_name' => 'method',
    'group_name' => 'group_response',
    'label' => 'Response',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '-1',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'description' => '',
        '5' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '-1',
    'fields' => array(
      '0' => 'field_method_return',
    ),
  );

  // Exported group: group_testing
  $groups['method-group_testing'] = array(
    'group_type' => 'standard',
    'type_name' => 'method',
    'group_name' => 'group_testing',
    'label' => 'Testing',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
        '5' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '0',
    'fields' => array(
      '0' => 'field_test_url_computed',
      '1' => 'field_rest_request_computed',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Request');
  t('Response');
  t('Testing');

  return $groups;
}
