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

  drupal_set_message("HERE");

  //main fieldset for all the form components 
  $form['main_fset'] = array(
      '#type' => 'fieldset',
      '#prefix' => '<div id="names-fieldset-wrapper">',
      '#suffix' => '</div>',
    );
  /*
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
  );*/


 
  //ADD TEXTFIELD BUTTON
  $form['add']['tfield'] = array(
      '#type' => 'submit',
      '#value' => t('Texfield'),
      '#submit' => array('add_tfield_callback'),//
      '#ajax' => array(
      'callback' => 'add_tfield_ajax_callback',
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
   if (empty($form_state['tfield_counter'])) {
     $form_state['tfield_counter'] = 1;
    }else{
      $form_state['tfield_counter']++;   
   
    }
    //$form_state['addtfield']=TRUE;
   $form_state['rebuild'] = TRUE;
}

function add_tfield_ajax_callback($form, $form_state) {
  // return $form['addtfield_fset'];


   for ($i = 0; $i < $form_state['tfield_counter']; $i++) {
    $form['addtfield_fset'][0] = array('#type' => 'fieldset');
      $form['addtfield_fset'][0]['ftitle'] = array(
        '#type' => 'textfield',
        '#title' => t('Label'),
        '#default_value' => ' ',
      );
      $form['addtfield_fset'][0]['fdesc'] = array(
        '#type' => 'textfield',
        '#title' => t('Placeholder'),
        '#markup' => "<p>Here's the description people</p>",
        '#default_value' => ' ',
      );
      $form['addtfield_fset'][0]['req'] = array(
        '#type' => 'checkbox',
        '#title' => t('Required'),
        '#default_value' => ' ',
      );
      $form['addtfield_fset'][0]['tfieldsubmit'] = array(
        '#type' => 'submit',
        '#submit' => array('addtoform_callback'),//
        '#ajax' => array(
          'callback' => 'addtoform_ajax_callback',
          'wrapper' => 'names-fieldset-wrapper',
        ),
        '#value' => t('Add'),
      );
      $form['addtfield_fset'][0]['tfieldsubmit2'] = array(
        '#type' => 'submit',
        '#submit' => array('remove_from_form'),
        '#value' => t('Remove'),
      );
   // }
   }
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

function addtoform_callback($form, &$form_state){
  drupal_set_message("HEY");
  $values = "Label: ".$form_state['values']['addtfield_fset'][0]['ftitle'];
  $values2 = "Placeholder: ".$form_state['values']['addtfield_fset'][0]['fdesc'];
  drupal_set_message($values);
  drupal_set_message($values2);
  $form_state['rebuild']=TRUE;
}

function addtoform_ajax_callback($form, &$form_state){
  return $form['main_fset'];
}
