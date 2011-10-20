<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function kendra_api_schema_user_default_permissions() {
  $permissions = array();

  // Exported permission: create attribute content
  $permissions['create attribute content'] = array(
    'name' => 'create attribute content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: create container content
  $permissions['create container content'] = array(
    'name' => 'create container content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: delete any attribute content
  $permissions['delete any attribute content'] = array(
    'name' => 'delete any attribute content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: delete any container content
  $permissions['delete any container content'] = array(
    'name' => 'delete any container content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: delete own attribute content
  $permissions['delete own attribute content'] = array(
    'name' => 'delete own attribute content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: delete own container content
  $permissions['delete own container content'] = array(
    'name' => 'delete own container content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit any attribute content
  $permissions['edit any attribute content'] = array(
    'name' => 'edit any attribute content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit any container content
  $permissions['edit any container content'] = array(
    'name' => 'edit any container content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit own attribute content
  $permissions['edit own attribute content'] = array(
    'name' => 'edit own attribute content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit own container content
  $permissions['edit own container content'] = array(
    'name' => 'edit own container content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  return $permissions;
}
