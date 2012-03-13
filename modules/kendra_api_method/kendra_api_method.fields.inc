<?php

/**
 * given a node ID, get the values for a list of fields from a referenced node
 * @param INT $nid
 * @return String title
 */
function computed_field_get_noderef_referenced_fields ($nid = 0, $fields = array()) {
	$node = node_load($nid);
	//watchdog('debug', 'Node = <pre>'. print_r($node, TRUE) .'</pre>');

	$out = array();
	foreach($fields as $fieldname) {
		$out[$fieldname] = $node->{$fieldname};
	}
	return $out;
}

function kendra_api_method_get_safe_param_example ($label = 'foo') {
	$safe_title = preg_replace('/[^\w]/', '_', $label);
	$safe_title = mb_strtolower($safe_title);
	return $safe_title;
}

/**
 * computed field : rest_request : compute

 * @param unknown_type $node
 * @param unknown_type $field
 * @param unknown_type $node_field
 */
function computed_field_field_rest_request_computed_compute(&$node, $field, &$node_field) {
	$url = KENDRA_API_ENDPOINT_BASE . KENDRA_API_ENDPOINT_PATH_PREFIX . $node->field_rest_uri_fragment[0]['value'];
	$method = $node->field_rest_http_method[0]['value'];
	$data = array();

	$my_tokens = array(
    'curl'
    ,'-v'
    //,'-H "Content-Type: application/json"'
    ,'-H "Content-Type: application/x-www-form-urlencoded"'
    ,'-b cookie.txt'
    ,'-c cookie.txt'
    ,'-X ' . $method
    );

    if ($method == 'GET') {
    	foreach($node->field_method_params as $i => $param) {
    		$nid = $param['nid'];
    		$fields = computed_field_get_noderef_referenced_fields($nid, array('title', 'type'));
    		if (isset($fields['title'])) {
    			if ($fields['type'] == 'attribute') {
    				$safe_title = kendra_api_method_get_safe_param_example($fields['title']);
    				$data[] = $safe_title . '=' . '$' . strtoupper($safe_title);
    			} else {
    				$safe_title = kendra_api_method_get_safe_param_example($fields['title']);
    				$data[] = $safe_title . '=' . '$' . strtoupper($safe_title);
    			}
    		}
    	}

    	if (!empty($data)) $url .= '?' . join('&', $data);

    } else if ($method == 'POST' || $method == 'PUT' || $method == 'DELETE') {
    	foreach($node->field_method_params as $i => $param) {
    		$nid = $param['nid'];
    		$fields = computed_field_get_noderef_referenced_fields($nid, array('title', 'type'));
    		if (isset($fields['title'])) {
    			if ($fields['type'] == 'attribute') {
    				$safe_title = kendra_api_method_get_safe_param_example($fields['title']);
    				$data[] = $safe_title . '=' . '$' . strtoupper($safe_title);
    			} else {
    				$safe_title = kendra_api_method_get_safe_param_example($fields['title']);
    				$data[] = $safe_title . '=' . '{}';
    			}
    		}
    	}

    	if (!empty($data)) {
    		$my_tokens[] = sprintf('--data "%s"', join('&', $data));
    	}
	/*
    	$payload = $node->field_rest_request_payload[0]['nid'];
    	if (!empty($payload)) {
    		$payload = computed_field_get_noderef_referenced_fields($nid, array('title', 'type'));
    		$safe_title = kendra_api_method_get_safe_param_example($payload['title']);
    		$my_tokens[] = sprintf('--data "\'{%s}\'"', $safe_title);
    	}
	*/
    }

    $my_tokens[] = '"' . $url . '"';
    $node_field[0]['value'] = join(' ', $my_tokens);
}

/**
 * computed field: test_url_computed_compute
 *
 * @param $node
 * @param $field
 * @param $node_field
 */
function computed_field_field_test_url_computed_compute(&$node, $field, &$node_field) {
	$url = KENDRA_API_ENDPOINT_BASE_WEB . '?';
	$url_path_prefix = KENDRA_API_ENDPOINT_PATH_PREFIX;
	$data = array();

	foreach($node->field_method_params as $i => $param) {
		$nid = $node->field_method_params[$i]['nid'];
		$fields = computed_field_get_noderef_referenced_fields($nid, array('title', 'type'));
		if (isset($fields['title'])) {
			if ($fields['type'] == 'attribute') {
				$safe_title = kendra_api_method_get_safe_param_example($fields['title']);
				$data[] = $safe_title . '=' . '$' . strtoupper($safe_title);
			} else {
				$safe_title = kendra_api_method_get_safe_param_example($fields['title']);
				$data[] = $safe_title . '=' . '{}';
			}
		}
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
 * computed field: rest_request : display
 * @param unknown_type $field
 * @param unknown_type $element
 * @param unknown_type $node
 */
function computed_field_field_rest_request_computed_display($field, $element, $node) {
	$display = $element['#item']['value'];
	return $display;
}

/**
 * computed field: test_url : display
 * @param unknown_type $field
 * @param unknown_type $element
 * @param unknown_type $node
 */
function computed_field_field_test_url_computed_display($field, $element, $node) {
	$url = $element['#item']['value'];
	$display = l($url,$url, array('attributes'=>array('target'=>'_top')));
	return $display;
}
