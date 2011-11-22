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

  // Exported group: group_publication_status
  $groups['container-group_publication_status'] = array(
    'group_type' => 'standard',
    'type_name' => 'container',
    'group_name' => 'group_publication_status',
    'label' => 'Publication Status',
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
    'weight' => '-3',
    'fields' => array(
      '0' => 'field_container_release',
      '1' => 'field_container_status',
      '2' => 'field_container_source',
    ),
  );

  // Exported group: group_schema
  $groups['container-group_schema'] = array(
    'group_type' => 'standard',
    'type_name' => 'container',
    'group_name' => 'group_schema',
    'label' => 'Schema Information',
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
    'weight' => '-4',
    'fields' => array(
      '0' => 'field_container_id',
      '1' => 'field_schema_name',
      '2' => 'field_rest_uri_fragment',
      '3' => 'field_container_privacy',
      '4' => 'field_container_desc',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Cardinality');
  t('Publication Status');
  t('Schema Information');

  return $groups;
}
