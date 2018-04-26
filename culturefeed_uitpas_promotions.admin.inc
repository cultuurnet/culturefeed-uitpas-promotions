<?php

/**
 * Form builder for UiTPAS promotions form.
 */
function culturefeed_uitpas_promotions_admin_settings() {

  $form['culturefeed_uitpas_promotions_url'] = array(
    '#type' => 'textfield',
    '#title' => t('URL UiTPAS promotions search'),
    '#default_value' => variable_get('culturefeed_uitpas_promotions_url', ''),
  );

  $form['culturefeed_uitpas_promotions_key'] = array(
    '#type' => 'textfield',
    '#title' => t('URL UiTPAS promotions key'),
    '#default_value' => variable_get('culturefeed_uitpas_promotions_key', ''),
  );

  $form['culturefeed_uitpas_promotions_uitdatabank_url'] = array(
    '#type' => 'textfield',
    '#title' => t('URL UiTdatabank API'),
    '#default_value' => variable_get('culturefeed_uitpas_promotions_uitdatabank_url', ''),
  );

  $form['culturefeed_uitpas_promotions_wildcard_search'] = array(
    '#type' => 'checkbox',
    '#title' => t('Wildcard Search'),
    '#description' => t('Wildcard based search of promotions, organizers and cities. When active, results for example "sta" will return "stadswinkel", "standaard" etc.'),
    '#default_value' => variable_get('culturefeed_uitpas_promotions_wildcard_search', true)
  );

  $form['culturefeed_uitpas_promotions_placeholder_search_field'] = array(
    '#type' => 'textfield',
    '#title' => t('Placeholder search field'),
    '#default_value' => variable_get('culturefeed_uitpas_promotions_placeholder_search_field', t('Name promotion, organizer or city')),
  );

  $form['culturefeed_uitpas_promotions_show_filter_on_map'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show cardsystem filter'),
    '#default_value' => variable_get('culturefeed_uitpas_promotions_show_filter_on_map', true),
  );

  $card_system_ids = array();
  $cf = DrupalCultureFeed::getConsumerInstance();
  $card_systems = $cf->uitpas()->getCardSystems('permanent');
  foreach ($card_systems as $card_system) {
    $card_system_ids[$card_system->name] = $card_system->name;
  }

  $form['culturefeed_uitpas_promotions_cardsystem_ids'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Pre filter promotions on card system'),
    '#options' => $card_system_ids,
    '#description' => t('Default will be shown all promotions of all card systems. You can choose to show only the promotions of your own card system. Choose which items you want to include in the filter.'),
    '#default_value' => variable_get('culturefeed_uitpas_promotions_cardsystem_ids', array()),
  );

  $form['culturefeed_uitpas_promotions_last_chance'] = array(
    '#type' => 'textfield',
    '#title' => t('Last chance'),
    '#description' => t('Items which will be unavailable soon, will automatically get the label "Laatste kans". You can set the amount in weeks before the items expires when the label needs to be visible.'),
    '#default_value' => variable_get('culturefeed_uitpas_promotions_last_chance', 2),
  );

  $form['culturefeed_uitpas_promotions_highlight'] = array(
    '#type' => 'checkbox',
    '#title' => t('Highlight promotions'),
    '#description' => t('Display highlighted promotions higher in the ranking (only when sorted on "Most recent").'),
    '#default_value' => variable_get('culturefeed_uitpas_promotions_highlight', false),
  );

  return system_settings_form($form);
}