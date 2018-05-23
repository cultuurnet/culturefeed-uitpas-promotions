<?php

function culturefeed_uitpas_promotions_preprocess_culturefeed_uitpas_promotions_search(&$variables) {
  global $base_url;

  foreach ($variables['card_systems'] as $key => $card_system) {
    if (!is_string($card_system)) {
      unset($variables['card_systems'][$key]);
    }
  }

  if (!empty($variables['card_systems'])) {
    $variables['card_systems_string'] = implode('|', $variables['card_systems']);
  }
  else {
    $variables['card_systems_string'] = '';
  }

  $variables['jsscript'] = $base_url . '/' . drupal_get_path('module', 'culturefeed_uitpas_promotions') . '/react/static/js/main.31c38f2d.js';
  $variables['thumb'] = $base_url . '/' . drupal_get_path('module', 'culturefeed_uitpas_promotions') . '/react/img/default-thumb.png';
}