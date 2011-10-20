<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function kendra_api_schema_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_attribute_cardinality
  $groups['attribute-group_attribute_cardinality'] = array(
    'group_type' => 'standard',
    'type_name' => 'attribute',
    'group_name' => 'group_attribute_cardinality',
    'label' => 'Cardinality',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '2',
        'label' => 'above',
        'teaser' => array(
          'format' => 'no_style',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'no_style',
          'exclude' => 0,
        ),
        'description' => '',
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '2',
    'fields' => array(
      '0' => 'field_attribute_min',
      '1' => 'field_attribute_max',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Cardinality');

  return $groups;
}
