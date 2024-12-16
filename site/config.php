<?php namespace ProcessWire;

/**
 * ProcessWire Configuration File
 *
 * Site-specific configuration for ProcessWire
 *
 * Please see the file /wire/config.php which contains all configuration options you may
 * specify here. Simply copy any of the configuration options from that file and paste
 * them into this file in order to modify them.
 *
 * SECURITY NOTICE
 * In non-dedicated environments, you should lock down the permissions of this file so
 * that it cannot be seen by other users on the system. For more information, please
 * see the config.php section at: https://processwire.com/docs/security/file-permissions/
 *
 * This file is licensed under the MIT license
 * https://processwire.com/about/license/mit/
 *
 * ProcessWire 3.x, Copyright 2023 by Ryan Cramer
 * https://processwire.com
 *
 */

if(!defined("PROCESSWIRE")) die();

/** @var Config $config */

/*** SITE CONFIG *************************************************************************/

// Let core API vars also be functions? So you can use $page or page(), for example.
$config->useFunctionsAPI = true;

// Use custom Page classes in /site/classes/ ? (i.e. template "home" => HomePage.php)
$config->usePageClasses = true;

// Use Markup Regions? (https://processwire.com/docs/front-end/output/markup-regions/)
$config->useMarkupRegions = false;

// Prepend this file in /site/templates/ to any rendered template files
$config->prependTemplateFile = '_init.php';

// Append this file in /site/templates/ to any rendered template files
//$config->appendTemplateFile = '_main.php';

// Allow template files to be compiled for backwards compatibility?
$config->templateCompile = false;

/*** INSTALLER CONFIG ********************************************************************/
/**
 * Installer: Database Configuration
 *
 */
$config->dbHost = 'localhost';
$config->dbName = 'vrealms';
$config->dbUser = 'spiercy';
$config->dbPass = 'ZT%8so&WFZEmia';
$config->dbPort = '3306';
$config->dbCharset = 'utf8mb4';

/**
 * Installer: User Authentication Salt
 *
 * This value was randomly generated for your system on 2024/06/08.
 * This should be kept as private as a password and never stored in the database.
 * Must be retained if you migrate your site from one server to another.
 * Do not change this value, or user passwords will no longer work.
 *
 */
$config->userAuthSalt = '5e40cf963984e2c6033a7ef0c878fa185c157747';

/**
 * Installer: Table Salt (General Purpose)
 *
 * Use this rather than userAuthSalt when a hashing salt is needed for non user
 * authentication purposes. Like with userAuthSalt, you should never change
 * this value or it may break internal system comparisons that use it.
 *
 */
$config->tableSalt = 'ffbb513fa9cddf2fdad1dced646006ab9988e36c';
/**
 * Installer: Database Configuration
 *
 */
$config->dbHost = 'localhost';
$config->dbName = 'vrealms';
$config->dbUser = 'spiercy';
$config->dbPass = 'ZT%8so&WFZEmia';
$config->dbPort = '3306';
$config->dbCharset = 'utf8mb4';

/**
 * Installer: User Authentication Salt
 *
 * This value was randomly generated for your system on 2024/06/08.
 * This should be kept as private as a password and never stored in the database.
 * Must be retained if you migrate your site from one server to another.
 * Do not change this value, or user passwords will no longer work.
 *
 */
$config->userAuthSalt = '5e40cf963984e2c6033a7ef0c878fa185c157747';

/**
 * Installer: Table Salt (General Purpose)
 *
 * Use this rather than userAuthSalt when a hashing salt is needed for non user
 * authentication purposes. Like with userAuthSalt, you should never change
 * this value or it may break internal system comparisons that use it.
 *
 */
$config->tableSalt = 'ffbb513fa9cddf2fdad1dced646006ab9988e36c';

/**
 * Installer: File Permission Configuration
 *
 */
$config->chmodDir = '0755'; // permission for directories created by ProcessWire
$config->chmodFile = '0644'; // permission for files created by ProcessWire

/**
 * Installer: Time zone setting
 *
 */
$config->timezone = 'America/Los_Angeles';

/**
 * Installer: Admin theme
 *
 */
$config->defaultAdminTheme = 'AdminThemeUikit';

/**
 * Installer: Unix timestamp of date/time installed
 *
 * This is used to detect which when certain behaviors must be backwards compatible.
 * Please leave this value as-is.
 *
 */
$config->installed = 1717828904;


/**
 * Installer: HTTP Hosts Whitelist
 *
 */
$config->httpHosts = array('localhost');


/**
 * Installer: Debug mode?
 *
 * When debug mode is true, errors and exceptions are visible.
 * When false, they are not visible except to superuser and in logs.
 * Should be true for development sites and false for live/production sites.
 *
 */
$config->debug = true;
