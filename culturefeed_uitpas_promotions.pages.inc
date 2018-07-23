<?php

function culturefeed_uitpas_promotions_search() {

  $setting_variables = _culturefeed_uitpas_promotions_get_setting_variables();
  $setting_variables['card_systems'] = variable_get('culturefeed_uitpas_promotions_cardsystem_ids', array());

  drupal_set_title(t('Promotions'), PASS_THROUGH);

  return array(
    '#attached' => array(
      'css' => array(
        drupal_get_path('module', 'culturefeed_uitpas_promotions') . '/react/static/css/main.27b775e4.css',
        'https://fonts.googleapis.com/css?family=Open+Sans:400,400i,600,700',
      )
    ),
    '#theme' => 'culturefeed_uitpas_promotions_search',
    '#url_uitpas' => $setting_variables['url_uitpas'] . $setting_variables['key_uitpas'] . '/',
    '#url_uitdatabank' => $setting_variables['url_uitdatabank'],
    '#fuzzy_search' => $setting_variables['fuzzy_search'],
    '#placeholder' => $setting_variables['placeholder'],
    '#filter_cardsystem' => $setting_variables['filter_cardsystem'],
    '#card_systems' => $setting_variables['card_systems'],
    '#last_chance' => $setting_variables['last_chance'],
    '#spotlight' => $setting_variables['spotlight']
  );
}

function culturefeed_uitpas_promotions_profile_search() {
  $uitpas_user = culturefeed_uitpas_get_uitpas_user();
  $passholder = $uitpas_user->passholder;
  $card_systems = $passholder->cardSystemSpecific;

  $setting_variables = _culturefeed_uitpas_promotions_get_setting_variables();
  $setting_variables['card_systems'] = array();

  foreach($card_systems as $card_system) {
    $setting_variables['card_systems'][$card_system->cardSystem->name] = $card_system->cardSystem->name;
  }

  drupal_set_title(t('My promotions'), PASS_THROUGH);

  return array(
    '#attached' => array(
      'css' => array(
        drupal_get_path('module', 'culturefeed_uitpas_promotions') . '/react/static/css/main.27b775e4.css',
        'https://fonts.googleapis.com/css?family=Open+Sans:400,400i,600,700',
      )
    ),
    '#theme' => 'culturefeed_uitpas_promotions_search',
    '#url_uitpas' => $setting_variables['url_uitpas'] . $setting_variables['key_uitpas'] . '/',
    '#url_uitdatabank' => $setting_variables['url_uitdatabank'],
    '#fuzzy_search' => $setting_variables['fuzzy_search'],
    '#placeholder' => $setting_variables['placeholder'],
    '#filter_cardsystem' => $setting_variables['filter_cardsystem'],
    '#card_systems' => $setting_variables['card_systems'],
    '#last_chance' => $setting_variables['last_chance'],
    '#spotlight' => $setting_variables['spotlight']
  );
}

function _culturefeed_uitpas_promotions_get_setting_variables() {
  $setting_variables = array();

  $setting_variables['url_uitpas'] = variable_get('culturefeed_uitpas_promotions_url', '');
  $setting_variables['key_uitpas'] = variable_get('culturefeed_uitpas_promotions_key', '');
  $setting_variables['url_uitdatabank'] = variable_get('culturefeed_uitpas_promotions_uitdatabank_url', '');
  $setting_variables['fuzzy_search'] = variable_get('culturefeed_uitpas_promotions_wildcard_search', 1);
  $setting_variables['placeholder'] = variable_get('culturefeed_uitpas_promotions_placeholder_search_field', t('Name promotion, organizer or city'));
  $setting_variables['filter_cardsystem'] = variable_get('culturefeed_uitpas_promotions_show_filter_on_map', 1);
  $setting_variables['last_chance'] = variable_get('culturefeed_uitpas_promotions_last_chance', 2);
  $setting_variables['spotlight'] = variable_get('culturefeed_uitpas_promotions_highlight', 0);

  return $setting_variables;
}