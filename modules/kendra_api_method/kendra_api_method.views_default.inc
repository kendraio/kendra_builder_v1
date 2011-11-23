<?php

/**
 * Implementation of hook_views_default_views().
 */
function kendra_api_method_views_default_views() {
  $views = array();

  // Exported view: methods
  $view = new view;
  $view->name = 'methods';
  $view->description = 'methods';
  $view->tag = 'methods';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'title' => array(
      'label' => 'Title',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
    'field_method_desc_value' => array(
      'label' => 'Description',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'label_type' => 'widget',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_method_desc_value',
      'table' => 'node_data_field_method_desc',
      'field' => 'field_method_desc_value',
      'relationship' => 'none',
    ),
    'field_rest_http_method_value' => array(
      'label' => 'REST HTTP Method',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 0,
        'ellipsis' => 0,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'label_type' => 'widget',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_rest_http_method_value',
      'table' => 'node_data_field_rest_http_method',
      'field' => 'field_rest_http_method_value',
      'relationship' => 'none',
    ),
    'field_rest_request_payload_nid' => array(
      'label' => 'REST Request Payload',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'label_type' => 'widget',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_rest_request_payload_nid',
      'table' => 'node_data_field_rest_request_payload',
      'field' => 'field_rest_request_payload_nid',
      'relationship' => 'none',
    ),
    'field_rest_uri_fragment_value' => array(
      'label' => 'REST URI Fragment',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => KENDRA_API_ENDPOINT_BASE_WEB . '?endpoint_path=' . KENDRA_API_ENDPOINT_PATH_PREFIX . '[field_rest_uri_fragment_value]&endpoint_method=[field_rest_http_method_value]&endpoint_data=',
        'link_class' => '',
        'alt' => 'Link to Kendra API Test page',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 0,
        'ellipsis' => 0,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'label_type' => 'widget',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_rest_uri_fragment_value',
      'table' => 'node_data_field_rest_uri_fragment',
      'field' => 'field_rest_uri_fragment_value',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
    ),
    'field_rpc_method_value' => array(
      'label' => 'RPC Method',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'label_type' => 'widget',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_rpc_method_value',
      'table' => 'node_data_field_rpc_method',
      'field' => 'field_rpc_method_value',
      'relationship' => 'none',
    ),
    'field_method_return_nid' => array(
      'label' => 'Return Object',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'label_type' => 'widget',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_method_return_nid',
      'table' => 'node_data_field_method_return',
      'field' => 'field_method_return_nid',
      'relationship' => 'none',
    ),
    'field_method_source_url' => array(
      'label' => 'Source URL',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'label_type' => 'widget',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_method_source_url',
      'table' => 'node_data_field_method_source',
      'field' => 'field_method_source_url',
      'relationship' => 'none',
    ),
    'edit_node' => array(
      'label' => 'Edit',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'text' => '',
      'exclude' => 0,
      'id' => 'edit_node',
      'table' => 'node',
      'field' => 'edit_node',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'field_container_id_value' => array(
      'order' => 'ASC',
      'delta' => -1,
      'id' => 'field_container_id_value',
      'table' => 'node_data_field_container_id',
      'field' => 'field_container_id_value',
      'relationship' => 'field_container_attribute_nid',
    ),
    'field_attribute_id_value' => array(
      'order' => 'ASC',
      'delta' => -1,
      'id' => 'field_attribute_id_value',
      'table' => 'node_data_field_attribute_id',
      'field' => 'field_attribute_id_value',
      'relationship' => 'field_container_attribute_nid',
    ),
    'title' => array(
      'order' => 'ASC',
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('arguments', array(
    'nid' => array(
      'default_action' => 'default',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => '',
      'breadcrumb' => '',
      'default_argument_type' => 'node',
      'default_argument' => '',
      'validate_type' => 'node',
      'validate_fail' => 'ignore',
      'break_phrase' => 0,
      'not' => 0,
      'id' => 'nid',
      'table' => 'node',
      'field' => 'nid',
      'validate_user_argument_type' => 'uid',
      'validate_user_roles' => array(
        '2' => 0,
        '3' => 0,
      ),
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
      'default_options_div_prefix' => '',
      'default_argument_user' => 0,
      'default_argument_fixed' => '',
      'default_argument_php' => '',
      'validate_argument_node_type' => array(
        'container' => 'container',
        'attribute' => 0,
        'method' => 0,
        'use_case' => 0,
      ),
      'validate_argument_node_access' => 0,
      'validate_argument_nid_type' => 'nid',
      'validate_user_restrict_roles' => 0,
      'validate_argument_php' => '',
      'validate_argument_vocabulary' => array(
        '2' => 0,
        '3' => 0,
        '1' => 0,
      ),
      'validate_argument_type' => 'tid',
      'validate_argument_transform' => 0,
    ),
  ));
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'method' => 'method',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'status_extra' => array(
      'operator' => '=',
      'value' => '',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status_extra',
      'table' => 'node',
      'field' => 'status_extra',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'role',
    'role' => array(
      '3' => 3,
      '2' => 2,
    ),
  ));
  $handler->override_option('cache', array(
    'type' => 'time',
    'results_lifespan' => 3600,
    'output_lifespan' => 3600,
  ));
  $handler->override_option('title', 'Methods');
  $handler->override_option('header_format', '2');
  $handler->override_option('header_empty', 0);
  $handler->override_option('empty', 'No attributes');
  $handler->override_option('empty_format', '1');
  $handler->override_option('use_ajax', TRUE);
  $handler->override_option('items_per_page', 0);
  $handler->override_option('link_display', 'page_3');
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'asc',
    'columns' => array(
      'title' => 'title',
      'field_method_desc_value' => 'field_method_desc_value',
      'field_rest_http_method_value' => 'field_rest_http_method_value',
      'field_rest_request_payload_nid' => 'field_rest_request_payload_nid',
      'field_rest_uri_fragment_value' => 'field_rest_uri_fragment_value',
      'field_rpc_method_value' => 'field_rpc_method_value',
      'field_method_return_nid' => 'field_method_return_nid',
      'field_method_source_url' => 'field_method_source_url',
      'edit_node' => 'edit_node',
    ),
    'info' => array(
      'title' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'field_method_desc_value' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'field_rest_http_method_value' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'field_rest_request_payload_nid' => array(
        'separator' => '',
      ),
      'field_rest_uri_fragment_value' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'field_rpc_method_value' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'field_method_return_nid' => array(
        'separator' => '',
      ),
      'field_method_source_url' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'edit_node' => array(
        'separator' => '',
      ),
    ),
    'default' => 'title',
  ));
  $handler = $view->new_display('page', 'Methods VBO', 'page_4');
  $handler->override_option('style_plugin', 'bulk');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'asc',
    'columns' => array(
      'title' => 'title',
      'field_method_desc_value' => 'field_method_desc_value',
      'field_rest_http_method_value' => 'field_rest_http_method_value',
      'field_rest_request_payload_nid' => 'field_rest_request_payload_nid',
      'field_rest_uri_fragment_value' => 'field_rest_uri_fragment_value',
      'field_rpc_method_value' => 'field_rpc_method_value',
      'field_method_return_nid' => 'field_method_return_nid',
      'field_method_source_url' => 'field_method_source_url',
      'edit_node' => 'edit_node',
    ),
    'info' => array(
      'title' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'field_method_desc_value' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'field_rest_http_method_value' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'field_rest_request_payload_nid' => array(
        'separator' => '',
      ),
      'field_rest_uri_fragment_value' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'field_rpc_method_value' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'field_method_return_nid' => array(
        'separator' => '',
      ),
      'field_method_source_url' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'edit_node' => array(
        'separator' => '',
      ),
    ),
    'default' => '-1',
    'execution_type' => '1',
    'display_type' => '0',
    'hide_select_all' => 0,
    'skip_confirmation' => 0,
    'display_result' => 1,
    'merge_single_action' => 1,
    'selected_operations' => array(
      'views_bulk_operations_fields_action' => 'views_bulk_operations_fields_action',
      'node_mass_update:9c585624b9b3af0b4687d5f97f35e047' => 'node_mass_update:9c585624b9b3af0b4687d5f97f35e047',
      'node_save_action' => 'node_save_action',
      'node_unpublish_action' => 'node_unpublish_action',
      'auto_nodetitle_operations_update' => 'auto_nodetitle_operations_update',
      'pathauto_node_update_alias_multiple:620e193b20ba9caa374fea9ca0ad38f0' => 'pathauto_node_update_alias_multiple:620e193b20ba9caa374fea9ca0ad38f0',
      'node_assign_owner_action' => 0,
      'views_bulk_operations_delete_node_action' => 0,
      'node_mass_update:a27b9efabcd054685a549378b174ad11' => 0,
      'system_message_action' => 0,
      'views_bulk_operations_ruleset_action_rules_set_1' => 0,
      'views_bulk_operations_action' => 0,
      'views_bulk_operations_script_action' => 0,
      'node_make_sticky_action' => 0,
      'node_make_unsticky_action' => 0,
      'node_mass_update:c4d3b28efb86fd703619a50b74d43794' => 0,
      'views_bulk_operations_taxonomy_action' => 0,
      'views_bulk_operations_argument_selector_action' => 0,
      'node_promote_action' => 0,
      'node_mass_update:14de7d028b4bffdf2b4a266562ca18ac' => 0,
      'node_publish_action' => 0,
      'system_goto_action' => 0,
      'node_unpromote_action' => 0,
      'node_mass_update:8ce21b08bb8e773d10018b484fe4815e' => 0,
      'system_send_email_action' => 0,
      'node_mass_update:0ccad85c1ebe4c9ceada1aa64293b080' => 0,
      'node_unpublish_by_keyword_action' => 0,
    ),
    'views_bulk_operations_fields_action' => array(
      'php_code' => 0,
      'display_fields' => array(
        '_all_' => '_all_',
      ),
      '_error_element_base' => 'style_options][views_bulk_operations_fields_action][',
    ),
  ));
  $handler->override_option('path', 'methods-VBO');
  $handler->override_option('menu', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler = $view->new_display('page', 'Page', 'page_2');
  $handler->override_option('path', 'methods');
  $handler->override_option('menu', array(
    'type' => 'normal',
    'title' => 'Methods',
    'description' => '',
    'weight' => '0',
    'name' => 'primary-links',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));

  $views[$view->name] = $view;

  // Exported view: methods_json
  $view = new view;
  $view->name = 'methods_json';
  $view->description = 'Methods JSON';
  $view->tag = 'methods_json';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'field_rest_uri_fragment_value' => array(
      'label' => 'target',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => KENDRA_API_ENDPOINT_BASE_WEB . '?endpoint_path=' . KENDRA_API_ENDPOINT_PATH_PREFIX . '[field_rest_uri_fragment_value]&endpoint_method=[field_rest_http_method_value]&endpoint_data=',
        'link_class' => '',
        'alt' => 'Link to Kendra API Test page',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 0,
        'ellipsis' => 0,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'label_type' => 'custom',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_rest_uri_fragment_value',
      'table' => 'node_data_field_rest_uri_fragment',
      'field' => 'field_rest_uri_fragment_value',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
    ),
    'field_rest_http_method_value' => array(
      'label' => 'transport',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 0,
        'ellipsis' => 0,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'label_type' => 'custom',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_rest_http_method_value',
      'table' => 'node_data_field_rest_http_method',
      'field' => 'field_rest_http_method_value',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
    ),
    'nothing' => array(
      'label' => 'envelope',
      'alter' => array(
        'text' => 'URL',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 0,
      'id' => 'nothing',
      'table' => 'views',
      'field' => 'nothing',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'nothing_1' => array(
      'label' => 'contentType',
      'alter' => array(
        'text' => 'application/json',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 0,
      'id' => 'nothing_1',
      'table' => 'views',
      'field' => 'nothing',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'field_rest_request_payload_nid' => array(
      'label' => 'parameters',
      'alter' => array(
        'alter_text' => 0,
        'text' => '[ { "name": "[field_rest_request_payload]" } ]',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'label_type' => 'custom',
      'format' => 'plain',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_rest_request_payload_nid',
      'table' => 'node_data_field_rest_request_payload',
      'field' => 'field_rest_request_payload_nid',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
    ),
    'field_method_return_nid' => array(
      'label' => 'return',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'label_type' => 'custom',
      'format' => 'plain',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_method_return_nid',
      'table' => 'node_data_field_method_return',
      'field' => 'field_method_return_nid',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
    ),
  ));
  $handler->override_option('sorts', array(
    'field_rest_uri_fragment_value' => array(
      'order' => 'ASC',
      'delta' => -1,
      'id' => 'field_rest_uri_fragment_value',
      'table' => 'node_data_field_rest_uri_fragment',
      'field' => 'field_rest_uri_fragment_value',
      'relationship' => 'none',
    ),
    'field_rpc_method_value' => array(
      'order' => 'ASC',
      'delta' => -1,
      'id' => 'field_rpc_method_value',
      'table' => 'node_data_field_rpc_method',
      'field' => 'field_rpc_method_value',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'method' => 'method',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'status_extra' => array(
      'operator' => '=',
      'value' => '',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status_extra',
      'table' => 'node',
      'field' => 'status_extra',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'role',
    'role' => array(
      '3' => 3,
      '2' => 2,
    ),
  ));
  $handler->override_option('cache', array(
    'type' => 'time',
    'results_lifespan' => 3600,
    'output_lifespan' => 3600,
  ));
  $handler->override_option('title', 'Methods');
  $handler->override_option('header_format', '2');
  $handler->override_option('header_empty', 0);
  $handler->override_option('empty', 'No attributes');
  $handler->override_option('empty_format', '1');
  $handler->override_option('use_ajax', TRUE);
  $handler->override_option('items_per_page', 0);
  $handler->override_option('link_display', 'page_3');
  $handler->override_option('style_plugin', 'views_json');
  $handler->override_option('style_options', array(
    'root_object' => 'services',
    'top_child_object' => 'service',
    'field_output' => 'normal',
    'plaintext_output' => 1,
    'format' => 'simple',
    'jsonp_prefix' => '',
    'content_type' => 'default',
    'using_views_api_mode' => 0,
  ));
  $handler = $view->new_display('page', 'Page', 'page_2');
  $handler->override_option('path', 'methods.json');
  $handler->override_option('menu', array(
    'type' => 'normal',
    'title' => 'Methods',
    'description' => '',
    'weight' => '0',
    'name' => 'primary-links',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));

  $views[$view->name] = $view;

  return $views;
}
