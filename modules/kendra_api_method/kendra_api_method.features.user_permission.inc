<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function kendra_api_method_user_default_permissions() {
  $permissions = array();

  // Exported permission: create method content
  $permissions['create method content'] = array(
    'name' => 'create method content',
    'roles' => array(),
  );

  // Exported permission: delete any method content
  $permissions['delete any method content'] = array(
    'name' => 'delete any method content',
    'roles' => array(),
  );

  // Exported permission: delete own method content
  $permissions['delete own method content'] = array(
    'name' => 'delete own method content',
    'roles' => array(),
  );

  // Exported permission: edit any method content
  $permissions['edit any method content'] = array(
    'name' => 'edit any method content',
    'roles' => array(),
  );

  // Exported permission: edit own method content
  $permissions['edit own method content'] = array(
    'name' => 'edit own method content',
    'roles' => array(),
  );

  return $permissions;
}
