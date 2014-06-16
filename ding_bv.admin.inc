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
  $agency_id = variable_get('ting_agency', '');
  if (empty($agency_id)) {
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

  $options = array(
    'not on' => t('All pages except those listed'),
    'on' => t('Only the listed pages'),
  );

  $form['ding_bv_visibility_type'] = array(
    '#type' => 'radios',
    '#title' => t('Show block on specific pages'),
    '#options' => $options,
    '#default_value' => variable_get('ding_bv_visibility_type', 'not on'),
  );

  $description = t("Specify pages by using their paths. Enter one path per line. The '*' character is a wildcard. Example paths are %blog for the blog page and %blog-wildcard for every personal blog. %front is the front page.", array('%blog' => 'blog', '%blog-wildcard' => 'blog/*', '%front' => '<front>'));

  $form['ding_bv_visibility_pages'] = array(
    '#type' => 'textarea',
    '#title' => '<span class="element-invisible">' . t('Pages') . '</span>',
    '#default_value' => variable_get('ding_bv_visibility_pages', ''),
    '#description' => $description,
  );

  return system_settings_form($form);
}
