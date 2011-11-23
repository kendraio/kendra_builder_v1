<?php

/**
 * given a node ID, get the title of a referenced node
 * @param INT $nid
 * @return String title
 */
function computed_field_get_noderef_referenced_title ($nid = 0) {
	$node = node_load($nid);
	watchdog('CF:get_noderef_referenced_title', '<pre>'. print_r($node, TRUE) .'</pre>');
	$value = $node->title;
	return $value;
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
    ,'-H "Content-Type: application/json"'
    ,'-X ' . $method
    );
    $placeholders = array('foo','bar','baz','qux');
    reset($placeholders);

    if ($method == 'GET') {
    	foreach($node->field_method_params as $i => $param) {
    		watchdog('CF:rest_request_computed_compute', '<pre>'. print_r($param, TRUE) .'</pre>');
    		$nid = $param['nid'];
    		$value = computed_field_get_noderef_referenced_title($nid);
    		$data[] = urlencode($value . '=' . current($placeholders));
    		next($placeholders);
    	}

    	$url .= join('&', $data);

    } else if ($method == 'POST' || $method == 'PUT' || $method == 'DELETE') {
    	foreach($node->field_method_params as $i => $param) {
    		watchdog('CF:rest_request_computed_compute', '<pre>'. print_r($param, TRUE) .'</pre>');
    		$nid = $param['nid'];
    		$value = computed_field_get_noderef_referenced_title($nid);
    		$data[] = urlencode($value . '=' . current($placeholders));
    		next($placeholders);
    	}

    	if (!empty($data)) {
    		$my_tokens[] = sprintf('--data "%s"', join('&', $data));
    	}
    }

    $my_tokens[] = $url;
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
	$url = KENDRA_API_ENDPOINT_BASE . '?';
	$url_path_prefix = KENDRA_API_ENDPOINT_PATH_PREFIX;
	$data = array();
	$placeholders = array('foo','bar','baz','qux');
	reset($placeholders);

	foreach($node->field_method_params as $i => $param) {
		$nid = $node->field_method_params[i]['nid'];
		$value = computed_field_get_noderef_referenced_title($nid);
		$data[] = $value . '=' . current($placeholders);
		next($placeholders);
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
	$display = l($url,$url);
	return $display;
}
