<?php

function culturefeed_uitpas_promotions_search() {
  $url_uitpas = variable_get('culturefeed_uitpas_promotions_url', '');
  $url_uitdatabank = variable_get('culturefeed_uitpas_promotions_uitdatabank_url', '');
  $fuzzy_search = variable_get('culturefeed_uitpas_promotions_wildcard_search', 1);
  $placeholder = variable_get('culturefeed_uitpas_promotions_placeholder_search_field', t('Name promotion, organizer or city'));
  $filter_cardsystem = variable_get('culturefeed_uitpas_promotions_show_filter_on_map', 1);
  $card_systems = variable_get('culturefeed_uitpas_promotions_cardsystem_ids', array());
  $last_chance = variable_get('culturefeed_uitpas_promotions_last_chance', 2);
  $spotlight = variable_get('culturefeed_uitpas_promotions_highlight', 0);

  return array(
    '#attached' => array(
      'css' => array(
        drupal_get_path('module', 'culturefeed_uitpas_promotions') . '/react/build/static/css/main.0df84700.css',
        'https://fonts.googleapis.com/css?family=Open+Sans:400,400i,600,700',
      )
    ),
    '#theme' => 'culturefeed_uitpas_promotions_search',
    '#url_uitpas' => $url_uitpas,
    '#url_uitdatabank' => $url_uitdatabank,
    '#fuzzy_search' => $fuzzy_search,
    '#placeholder' => $placeholder,
    '#filter_cardsystem' => $filter_cardsystem,
    '#card_systems' => $card_systems,
    '#last_chance' => $last_chance,
    '#spotlight' => $spotlight
  );
}