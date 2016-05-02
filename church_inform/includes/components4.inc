<?php

/**
 * @file
 * Webform module component handling.
 */

/**
 * Provides interface and database handling for editing components of a webform.
 *
 * @author Nathan Haug <nate@lullabot.com>
 */

/**
 * Overview page of all components for this webform.
 */



//Ask for details that will build the form 
/* ADD FIELDS */
//this is the form to create forms 
function add_fields_form($form, &$form_state, $no_js_use = FALSE){
  $form['#tree'] = TRUE;

  $form['add'] = array(
      '#prefix' => '<div id="form-buttons">',
      '#suffix' => '</div>',
    );

  //main fieldset for all the form components 
  $form['main_fset'] = array(
      '#type' => 'fieldset',
      '#prefix' => '<div id="names-fieldset-wrapper">',
      '#suffix' => '</div>',
    );

  $form['addnumber_fset'] = array(
    '#type' => 'fieldset',
    //'#title' => t('People coming to the picnic'),
    // Set up the wrapper so that AJAX will be able to replace the fieldset.
    '#prefix' => '<div id="names-fieldset-wrapper">',
    '#suffix' => '</div>',
  );
  //return this fieldset when user asks for an additional extfield
  $form['addtfield_fset'] = array(
    '#type' => 'fieldset',
    //'#title' => t('People coming to the picnic'),
    // Set up the wrapper so that AJAX will be able to replace the fieldset.
    '#prefix' => '<div id="names-fieldset-wrapper">',
    '#suffix' => '</div>',
  );

  $form['addcheckbox_fset'] = array(
    '#type' => 'fieldset',
    //'#title' => t('People coming to the picnic'),
    // Set up the wrapper so that AJAX will be able to replace the fieldset.
    '#prefix' => '<div id="names-fieldset-wrapper">',
    '#suffix' => '</div>',
  );


   

  //increment
  //if (empty($form_state['addtfield_fset_count'])) {
  //  $form_state['addtfield_fset_count'] = 1;
  
  if (empty($form_state['tfield_counter'])) {
    $form_state['tfield_counter'] = 1;
  }

  if (empty($form_state['checkbox_counter'])) {
    $form_state['checkbox_counter'] = 1;
  }

  if (empty($form_state['num_counter'])) {
    $form_state['num_counter'] = 1;
  }
  /*for ($i = 0; $i < $form_state['addtfield_fset_count']; $i++) {
    $form['mainset']['tfield'][$i] = array(
      '#type' => 'textfield',
      '#title' => t('Name'),
    );
  }*/

  //ADD TEXT FIELD
  for ($i = 0; $i < $form_state['tfield_counter']; $i++) {
    $form['addtfield_fset'][$i] = array('#type' => 'fieldset');
      $form['addtfield_fset'][$i]['ftitle'] = array(
        '#type' => 'textfield',
        '#title' => t('Label'),
        '#default_value' => ' ',
      );
      $form['addtfield_fset'][$i]['fdesc'] = array(
        '#type' => 'textfield',
        '#title' => t('Placeholder'),
        '#markup' => "<p>Here's the description people</p>",
        '#default_value' => ' ',
      );
      $form['addtfield_fset'][$i]['req'] = array(
        '#type' => 'checkbox',
        '#title' => t('Required'),
        '#default_value' => ' ',
      );
      $form['addtfield_fset'][$i]['tfieldsubmit'] = array(
        '#type' => 'button',
        '#submit' => array('add_to_form'),
        '#value' => t('Add'),
      );
      $form['addtfield_fset'][$i]['tfieldsubmit2'] = array(
        '#type' => 'submit',
        '#submit' => array('remove_from_form'),
        '#value' => t('Remove'),
      );
  }
   

  //}//end of for-loop


  for($i=0; $i<$form_state['checkbox_counter']; $i++){
    $form['addcheckbox_fset'][$i] = array('#type' => 'fieldset');
    $form['addcheckbox_fset'][$i]['ftitle'] = array(
      '#type' => 'textfield',
      '#title' => t('Label'),
      '#default_value' => ' ',
    );
    $form['addcheckbox_fset'][$i]['fdesc'] = array(
      '#type' => 'textarea',
      '#title' => t('Options'),
      '#cols' => 10,
      '#resizable' => FALSE,
      '#markup' => "<p>Here's the description people</p>",
      '#default_value' => t('Separate options with a comma (ex: One,Two,Tree)'),
    );
    $form['addcheckbox_fset'][$i]['tfieldsubmit'] = array(
      '#type' => 'submit',
      '#submit' => array('add_to_form'),
      '#value' => t('Add'),
    );
    $form['addcheckbox_fset'][$i]['tfieldsubmit2'] = array(
      '#type' => 'submit',
      '#submit' => array('remove_from_form'),
      '#value' => t('Remove'),
    );
  }


  for($i=0; $i<$form_state['num_counter']; $i++){
    $form['addnumber_fset'][$i] = array('#type' => 'fieldset');
    $form['addnumber_fset'][$i]['ntitle'] = array(
        '#type' => 'textfield',
        '#title' => t('Label'),
        '#default_value' => ' ',
      );
    $form['addnumber_fset'][$i]['tfieldsubmit'] = array(
      '#type' => 'submit',
      '#submit' => array('add_to_form'),
      '#value' => t('Add'),
    );
    $form['addnumber_fset'][$i]['tfieldsubmit2'] = array(
      '#type' => 'submit',
      '#submit' => array('remove_from_form'),
      '#value' => t('Remove'),
    );
  }

  //ADD BUTTONS
  
  //ADD TEXTFIELD BUTTON
  $form['add']['tfield'] = array(
      '#type' => 'submit',
      '#value' => t('Texfield'),
      '#submit' => array('add_tfield_callback'),//
      '#ajax' => array(
      'callback' => 'addfield_ajax_callback',
      'wrapper' => 'names-fieldset-wrapper',
      ),
      '#attributes' => array(
          'class' => array(
          'add-field-class' 
          ),
      ),
  );


   $form['add']['checkbox'] = array(
      '#type' => 'submit',
      '#value' => t('Checkbox'),
      '#submit' => array('add_checkbox_callback'),
      '#ajax' => array(
      'callback' => 'addfield_ajax_callback',
      'wrapper' => 'names-fieldset-wrapper',
      ),
      '#attributes' => array(
          'class' => array(
          'add-field-class' 
          ),
      ),
  );

   $form['add']['number'] = array(
      '#type' => 'submit',
      '#value' => t('Number'),
      '#submit' => array('add_num_callback'),
      '#ajax' => array(
      'callback' => 'addfield_ajax_callback',
      'wrapper' => 'replace-this-number',
      ),
      '#attributes' => array(
          'class' => array(
          'add-field-class' 
          ),
      ),
  );

   $form['add']['date'] = array(
      '#type' => 'button',
      '#value' => t('Date'),
      '#ajax' => array(
      'callback' => 'add_date_callback',
      'wrapper' => 'replace-this-date',
      'method' => 'replace',
      ),
      '#attributes' => array(
          'class' => array(
          'add-field-class' 
          ),
      ),
  );

  $form['add']['select'] = array(
      '#type' => 'button',
      '#value' => t('Select options'),
      '#ajax' => array(
      'callback' => 'add_select_callback',
      'wrapper' => 'replace-this-select',
      'method' => 'replace',
      ),
      '#attributes' => array(
          'class' => array(
          'add-field-class' 
          ),
      ),
  );

   $form['add']['member'] = array(
      '#type' => 'button',
      '#value' => t('Member'),
      '#ajax' => array(
      'callback' => 'add_member_callback',
      'wrapper' => 'replace-this-member',
      'method' => 'replace',
      ),
      '#attributes' => array(
          'class' => array(
          'add-field-class' 
          ),
      ),
  );

   $form['add']['dprocess'] = array(
      '#type' => 'button',
      '#value' => t('Discipleship Process'),
      '#ajax' => array(
      'callback' => 'add_dprocess_callback',
      'wrapper' => 'replace-this-dprocess',
      'method' => 'replace',
      ),
      '#attributes' => array(
          'class' => array(
          'add-field-class' 
          ),
      ),
  );
  
  

  // build the initial field if this is not being rebuilt 
  // from ajax request  
  
  return $form;
}


function addfield_callback($form, &$form_state){
  $form_state['tfield_counter']= 1;
  $form_state['rebuild'] = TRUE;
}

function addfield_ajax_callback($form, &$form_state){
  return $form['main_fset'];
}


//Add textfield callback
function add_tfield_callback($form, &$form_state) {
   $form_state['tfield_counter']++;
   $form_state['rebuild'] = TRUE;
}

function add_tfield_ajax_callback($form, $form_state) {
  // return $form['addtfield_fset'];
  return $form['addtfield_fset'];
}


//Add checkbox callback
function add_checkbox_callback($form, &$form_state) {
   $form_state['checkbox_counter']++;
   $form_state['rebuild'] = TRUE;
}


function add_checkbox_ajax_callback($form, $form_state) {
   //return $form['addcheckbox_fset'];
  return $form['addcheckbox_fset'];
}


//add textfield accepting integers 
function add_num_callback($form, &$form_state) {
   $form_state['num_counter']++;
   $form_state['rebuild'] = TRUE;
}


function add_num_ajax_callback($form, $form_state) {
   //return $form['addnumber_fset'];
  return $form['addnumber_fset'];
}


//

function add_to_form($form,&$form_state){
  $values = "Label: ".$form_state['values']['addtfield_fset'][0]['ftitle'];
  $values2 = "Placeholder: ".$form_state['values']['addtfield_fset'][0]['fdesc'];
  drupal_set_message($values);
  drupal_set_message($values2);
}
