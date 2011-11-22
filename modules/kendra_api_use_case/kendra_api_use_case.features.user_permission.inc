<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function kendra_api_use_case_user_default_permissions() {
  $permissions = array();

  // Exported permission: create action content
  $permissions['create action content'] = array(
    'name' => 'create action content',
    'roles' => array(),
  );

  // Exported permission: create requirements content
  $permissions['create requirements content'] = array(
    'name' => 'create requirements content',
    'roles' => array(),
  );

  // Exported permission: create use_case content
  $permissions['create use_case content'] = array(
    'name' => 'create use_case content',
    'roles' => array(),
  );

  // Exported permission: delete any action content
  $permissions['delete any action content'] = array(
    'name' => 'delete any action content',
    'roles' => array(),
  );

  // Exported permission: delete any requirements content
  $permissions['delete any requirements content'] = array(
    'name' => 'delete any requirements content',
    'roles' => array(),
  );

  // Exported permission: delete any use_case content
  $permissions['delete any use_case content'] = array(
    'name' => 'delete any use_case content',
    'roles' => array(),
  );

  // Exported permission: delete own action content
  $permissions['delete own action content'] = array(
    'name' => 'delete own action content',
    'roles' => array(),
  );

  // Exported permission: delete own requirements content
  $permissions['delete own requirements content'] = array(
    'name' => 'delete own requirements content',
    'roles' => array(),
  );

  // Exported permission: delete own use_case content
  $permissions['delete own use_case content'] = array(
    'name' => 'delete own use_case content',
    'roles' => array(),
  );

  // Exported permission: edit any action content
  $permissions['edit any action content'] = array(
    'name' => 'edit any action content',
    'roles' => array(),
  );

  // Exported permission: edit any requirements content
  $permissions['edit any requirements content'] = array(
    'name' => 'edit any requirements content',
    'roles' => array(),
  );

  // Exported permission: edit any use_case content
  $permissions['edit any use_case content'] = array(
    'name' => 'edit any use_case content',
    'roles' => array(),
  );

  // Exported permission: edit own action content
  $permissions['edit own action content'] = array(
    'name' => 'edit own action content',
    'roles' => array(),
  );

  // Exported permission: edit own requirements content
  $permissions['edit own requirements content'] = array(
    'name' => 'edit own requirements content',
    'roles' => array(),
  );

  // Exported permission: edit own use_case content
  $permissions['edit own use_case content'] = array(
    'name' => 'edit own use_case content',
    'roles' => array(),
  );

  return $permissions;
}
