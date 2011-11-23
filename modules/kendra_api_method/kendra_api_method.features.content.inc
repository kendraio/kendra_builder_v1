<?php

/**
 * computed field : rest_request : compute

 * @param unknown_type $node
 * @param unknown_type $field
 * @param unknown_type $node_field
 */
function computed_field_field_rest_request_computed_compute($node, $field, $node_field) {
	$url = 'http://api.kendra.org/saracen/0.1' . $node->field_rest_uri_fragment[0]['value'];
	$method = $node->field_rest_http_method[0]['value'];
	$data = array();

	$my_tokens = array(
    'curl'
    ,'-v'
    ,'-H "Content-Type: application/json"'
    ,'-X ' . $method
    );

    if ($method == 'GET') {
    	foreach($node->field_method_params as $i => $param) {
    		// var_dump($param);
    		$data[] = urlencode($param['value'] . '=XXXXX');
    	}

    	$url .= join('&', $data);

    } else if ($method == 'POST' || $method == 'PUT' || $method == 'DELETE') {
    	foreach($node->field_method_params as $i => $param) {
    		// var_dump($param);
    		$data[] = urlencode($param['value'] . '=XXXXX');
    	}

    	if (!empty($data)) {
    		$my_tokens[] = sprintf('--data "%s"', join('&', $data));
    	}
    }

    $my_tokens[] = $url;
    $node_field[0]['value'] = join(' ', $my_tokens);
}

/**
 * computed field: rest_request : display
 * @param unknown_type $field
 * @param unknown_type $element
 * @param unknown_type $node
 */
function computed_field_field_rest_request_computed_display($field, $element, $node) {
	$display = $node_field_item['value'];
}

/**
 * computed field: test_url : display
 * @param unknown_type $field
 * @param unknown_type $element
 * @param unknown_type $node
 */
function computed_field_field_test_url_computed_display($field, $element, $node) {
	$url = $node_field_item['value'];
	$display = l($url,$url);
}

/**
 * computed field: test_url_computed_compute
 *
 * @param $node
 * @param $field
 * @param $node_field
 */
function computed_field_field_test_url_computed_compute($node, $field, $node_field) {
	$url = 'http://trial.saracen.kendra.org/kendra-api-test?';
	$url_path_prefix = 'saracen/0.1';
	$data = array();

	foreach($node->field_method_params as $i => $param) {
		//var_dump($node->field_method_params[i]);
		$data[] = $node->field_method_params[i]['value'] . '=XXXXX';
	}

	$url .= join('&',
	array(
        'endpoint_method='.$node->field_rest_http_method[0]['value']
	,'endpoint_path=' . $url_path_prefix . $node->field_rest_uri_fragment[0]['value']
	,'endpoint_data=' . urlencode(join('&', $data))
	));

	$node_field[0]['value'] = $url;
}

/**
 * Implementation of hook_content_default_fields().
 */
function kendra_api_method_content_default_fields() {
	$fields = array();

	// Exported field: field_method_desc
	$fields['method-field_method_desc'] = array(
    'field_name' => 'field_method_desc',
    'type_name' => 'method',
    'display_settings' => array(
      'weight' => '-4',
      'parent' => '',
      'label' => array(
        'format' => 'above',
	),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
	),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
	),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
	),
	),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '1',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => '3',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_method_desc][0][value',
	),
	),
      'default_value_php' => NULL,
      'label' => 'Description',
      'weight' => '-4',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
	),
	);

	// Exported field: field_method_params
	$fields['method-field_method_params'] = array(
    'field_name' => 'field_method_params',
    'type_name' => 'method',
    'display_settings' => array(
      'weight' => '12',
      'parent' => 'group_request',
      'label' => array(
        'format' => 'above',
	),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
	),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
	),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
	),
	),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '1',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'attribute' => 'attribute',
      'action' => 0,
      'book' => 0,
      'container' => 0,
      'method' => 0,
      'requirements' => 0,
      'use_case' => 0,
	),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
          '_error_element' => 'default_value_widget][field_method_params][0][nid][nid',
	),
	),
      'default_value_php' => NULL,
      'label' => 'Parameters',
      'weight' => '12',
      'description' => '',
      'type' => 'noderefcreate_autocomplete',
      'module' => 'noderefcreate',
	),
	);

	// Exported field: field_method_return
	$fields['method-field_method_return'] = array(
    'field_name' => 'field_method_return',
    'type_name' => 'method',
    'display_settings' => array(
      'weight' => '-2',
      'parent' => 'group_response',
      'label' => array(
        'format' => 'above',
	),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
	),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
	),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
	),
	),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'attribute' => 'attribute',
      'container' => 'container',
      'action' => 0,
      'book' => 0,
      'method' => 0,
      'requirements' => 0,
      'use_case' => 0,
	),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
          '_error_element' => 'default_value_widget][field_method_return][0][nid][nid',
	),
	),
      'default_value_php' => NULL,
      'size' => '60',
      'label' => 'Return Object',
      'weight' => '-2',
      'description' => '',
      'type' => 'nodereference_autocomplete',
      'module' => 'nodereference',
	),
	);

	// Exported field: field_method_source
	$fields['method-field_method_source'] = array(
    'field_name' => 'field_method_source',
    'type_name' => 'method',
    'display_settings' => array(
      'weight' => '-3',
      'parent' => '',
      'label' => array(
        'format' => 'inline',
	),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
	),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
	),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
	),
	),
    'widget_active' => '1',
    'type' => 'link',
    'required' => '0',
    'multiple' => '0',
    'module' => 'link',
    'active' => '1',
    'attributes' => array(
      'target' => 'default',
      'rel' => 'nofollow',
      'class' => '',
      'title' => '',
	),
    'display' => array(
      'url_cutoff' => '80',
	),
    'url' => 0,
    'title' => 'none',
    'title_value' => '',
    'enable_tokens' => '',
    'validate_url' => 1,
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'title' => '',
          'url' => '',
	),
	),
      'default_value_php' => NULL,
      'label' => 'Source URL',
      'weight' => '-3',
      'description' => 'If this method is imported from an external source, provide a link to where it is documented here.',
      'type' => 'link',
      'module' => 'link',
	),
	);

	// Exported field: field_rest_http_method
	$fields['method-field_rest_http_method'] = array(
    'field_name' => 'field_rest_http_method',
    'type_name' => 'method',
    'display_settings' => array(
      'weight' => '8',
      'parent' => 'group_request',
      'label' => array(
        'format' => 'inline',
	),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
	),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
	),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
	),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
	),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
	),
	),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => 'GET
	POST
	PUT
	DELETE',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => 'GET',
          '_error_element' => 'default_value_widget][field_rest_http_method][0][value',
	),
	),
      'default_value_php' => NULL,
      'label' => 'REST HTTP Method',
      'weight' => '8',
      'description' => '',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
	),
	);

	// Exported field: field_rest_request_computed
	$fields['method-field_rest_request_computed'] = array(
    'field_name' => 'field_rest_request_computed',
    'type_name' => 'method',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
	),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
	),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
	),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
	),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
	),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
	),
	),
    'widget_active' => '1',
    'type' => 'computed',
    'required' => '0',
    'multiple' => '0',
    'module' => 'computed_field',
    'active' => '1',
	//    'code' => '',
	//'display_format' => '',
    'store' => 1,
    'data_type' => 'text',
    'data_length' => '4096',
    'data_not_NULL' => 0,
    'data_default' => '',
    'data_sortable' => 1,
    'widget' => array(
      'default_value' => NULL,
      'default_value_php' => NULL,
      'label' => 'REST Request',
      'weight' => '9',
      'description' => '',
      'type' => 'computed',
      'module' => 'computed_field',
	),
	);

	// Exported field: field_rest_request_payload
	$fields['method-field_rest_request_payload'] = array(
    'field_name' => 'field_rest_request_payload',
    'type_name' => 'method',
    'display_settings' => array(
      'weight' => '10',
      'parent' => 'group_request',
      'label' => array(
        'format' => 'inline',
	),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
	),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
	),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
	),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
	),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
	),
	),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'container' => 'container',
      'action' => 0,
      'attribute' => 0,
      'book' => 0,
      'method' => 0,
      'requirements' => 0,
      'use_case' => 0,
	),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
          '_error_element' => 'default_value_widget][field_rest_request_payload][0][nid][nid',
	),
	),
      'default_value_php' => NULL,
      'label' => 'REST Request Payload',
      'weight' => '10',
      'description' => '',
      'type' => 'nodereference_autocomplete',
      'module' => 'nodereference',
	),
	);

	// Exported field: field_rest_uri_fragment
	$fields['method-field_rest_uri_fragment'] = array(
    'field_name' => 'field_rest_uri_fragment',
    'type_name' => 'method',
    'display_settings' => array(
      'weight' => '9',
      'parent' => 'group_request',
      'label' => array(
        'format' => 'inline',
	),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
	),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
	),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
	),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
	),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
	),
	),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '128',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_rest_uri_fragment][0][value',
	),
	),
      'default_value_php' => NULL,
      'label' => 'REST URI Fragment',
      'weight' => '9',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
	),
	);

	// Exported field: field_rpc_method
	$fields['method-field_rpc_method'] = array(
    'field_name' => 'field_rpc_method',
    'type_name' => 'method',
    'display_settings' => array(
      'weight' => '11',
      'parent' => 'group_request',
      'label' => array(
        'format' => 'inline',
	),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
	),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
	),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
	),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
	),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
	),
	),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '60',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_rpc_method][0][value',
	),
	),
      'default_value_php' => NULL,
      'label' => 'RPC Method',
      'weight' => '11',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
	),
	);

	// Exported field: field_test_url_computed
	$fields['method-field_test_url_computed'] = array(
    'field_name' => 'field_test_url_computed',
    'type_name' => 'method',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
	),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
	),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
	),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
	),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
	),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
	),
	),
    'widget_active' => '1',
    'type' => 'computed',
    'required' => '0',
    'multiple' => '0',
    'module' => 'computed_field',
    'active' => '1',
	//'code' => '',
	//'display_format' => '',
    'store' => 1,
    'data_type' => 'varchar',
    'data_length' => '256',
    'data_not_NULL' => 0,
    'data_default' => 'http://trial.saracen.kendra.org/kendra-api-test',
    'data_sortable' => 1,
    'widget' => array(
      'default_value' => NULL,
      'default_value_php' => NULL,
      'label' => 'Test URL',
      'weight' => '8',
      'description' => '',
      'type' => 'computed',
      'module' => 'computed_field',
	),
	);

	// Translatables
	// Included for use with string extractors like potx.
	t('Description');
	t('Parameters');
	t('REST HTTP Method');
	t('REST Request');
	t('REST Request Payload');
	t('REST URI Fragment');
	t('RPC Method');
	t('Return Object');
	t('Source URL');
	t('Test URL');

	return $fields;
}