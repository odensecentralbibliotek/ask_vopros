<?php

/**
 * @file
 * Administrative forms and pages for ding_bv.
 */

/**
 * Form builder.
 */
function ding_bv_settings($form, &$form_state) {
  // If ting is configured with an agency id, just use that.
  if (empty(variable_get('ting_agency', ''))) {
    $form['ding_bv_agency_id'] = array(
      '#type' => 'textfield',
      '#title' => t('Identification'),
      '#default_value' => variable_get('ding_bv_agency_id', ''),
      '#description' => t('Either a library code in the form of <em>DK-123456</em> or a custom string.'),
    );
  }

  $form['ding_bv_agency_mail'] = array(
    '#type' => 'textfield',
    '#title' => t('Local E-mail'),
    '#default_value' => variable_get('ding_bv_agency_mail', variable_get('site_mail', '')),
    '#description' => t('E-mail address which Biblioteksvagten can forward inquiries best answered locally to.'),
  );

  return system_settings_form($form);
}
