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


/* ADD FIELDS */
function add_fields_form($form, &$form_state){
  $form['#tree'] = TRUE;

  $form['add'] = array(
      '#prefix' => '<div id="form-buttons">',
      '#suffix' => '</div>',
    );


   $form['add']['tfield'] = array(
      '#type' => 'button',
      '#value' => t('Texfield'),
      '#ajax' => array(
      'callback' => 'add_tfield_callback',
      'wrapper' => 'replace-this',
      'method' => 'replace',
      ),
      '#attributes' => array(
          'class' => array(
          'add-field-class' 
          ),
      ),
  );

   $form['add']['fset'] = array(
      '#type' => 'button',
      '#value' => t('Fieldset'),
      '#ajax' => array(
      'callback' => 'add_fieldset_callback',
      'wrapper' => 'replace-this-fieldset',
      'method' => 'replace',
      ),
      '#attributes' => array(
          'class' => array(
          'add-field-class' 
          ),
      ),
  );

   $form['add']['textarea'] = array(
      '#type' => 'button',
      '#value' => t('Textarea'),
      '#ajax' => array(
      'callback' => 'add_textarea_callback',
      'wrapper' => 'replace-this-textarea',
      'method' => 'replace',
      ),
      '#attributes' => array(
          'class' => array(
          'add-field-class' 
          ),
      ),
  );

   $form['add']['checkbox'] = array(
      '#type' => 'button',
      '#value' => t('Checkbox'),
      '#ajax' => array(
      'callback' => 'add_checkbox_callback',
      'wrapper' => 'replace-this-checkbox',
      'method' => 'replace',
      ),
      '#attributes' => array(
          'class' => array(
          'add-field-class' 
          ),
      ),
  );

   $form['add']['number'] = array(
      '#type' => 'button',
      '#value' => t('Number'),
      '#ajax' => array(
      'callback' => 'add_number_callback',
      'wrapper' => 'replace-this-number',
      'method' => 'replace',
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
  
  $form['tfield1'] = array(
      '#type' => 'textfield',
      '#title' => 'Title here',
      '#prefix' => '<div id="replace-this">',
      '#suffix' => '</div>',
      '#tree' => TRUE,
  );

  $form['fset'] = array(
      '#type' => 'fieldset',
      '#title' => 'Title here',
      '#prefix' => '<div id="replace-this-fieldset">',
      '#suffix' => '</div>',
      '#tree' => TRUE,
  );

  // build the initial field if this is not being rebuilt 
  // from ajax request  
  if (!array_key_exists('clicked_button', $form_state)) {
      $form['tfield1'][0] = array(
          '#type' => 'textfield',
          '#title' => t('Okay'),
          );
  }else{
      foreach ($form_state['input']['tfield1'] as $i => $value) {
          $form['tfield1'][$i] = array(
          '#type' => 'textfield',
          '#title' => t(' here'),
          '#default_value' => $form_state['input']['tfield1'][$i],
          );
       }

       $last = count($form_state['input']['tfield1']);
        $form['tfield1'][$last] = array(
        '#type' => 'textfield',
        '#title' => t('Name'),
       );   
  }
       
 
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
   );
  
  $form['#submit'][] = 'my_form_add_more_submit';
  return $form;
}

function add_tfield_callback($form, &$form_state) {
  return $form['tfield'];
}


function add_fieldset_callback($form, &$form_state) {
        return $form['fset'];
}



function add_more($form, &$form_state) {
    $form_state['num_items']=$form_state['num_items']+5;
    $form_state['rebuild'] = TRUE;
}


function add_textfield_callback($form, $form_state) {
  return $form['example_fieldset'];
}

function ajax_example_simplest_1_callback($form, $form_state) {
  // The form has already been submitted and updated. We can return the replaced
  // item as it is.
  return $form['replace_textfield'];
}




function ajax_callback($form, &$form_state){
    $form_state['rebuild']=true;
    return $form['names'];
}


function my_form_form($form, &$form_state, $no_js_use = FALSE) {



        $form['add_more'] = array(
          '#type' => 'button',
          '#value' => t('Add More'),
          '#ajax' => array(
            'callback' => 'ajax_simplest_callback',
            'wrapper' => 'replace-this',
            'method' => 'replace',
           ),
        );

        $form['names'] = array(
          '#type' => 'fieldset',
          '#title' => 'Names',
          '#prefix' => '<div id="replace-this">',
          '#suffix' => '</div>',
          '#tree' => TRUE,
        );

        // build the initial field if this is not being rebuilt 
        // from ajax request
        if (!array_key_exists('clicked_button', $form_state)) {
          $form['names'][0] = array('#type' => 'textfield');
          /*$form['names'][0]['name'] = array(
            '#type' => 'textfield',
            '#title' => t('Name'),
            '#parent' => 'test',
          );
          $form['names'][0]['select'] = array(
            '#type' => 'select',
            '#title' => t('Select'),
            '#parent' => 'test',
            '#options'=>array('1'=>'One', '2'=>'Two', '3'=>'Three'),
          );*/
        } else {
          // otherwise add the fields for each existing value
          foreach ($form_state['input']['names'] as $i => $value) {
            $form['names'][$i] = array(
              '#type' => 'textfield', 
              '#title' => t('NEW'),
              );
           /* $form['names'][$i]['name'] = array(
              '#type' => 'textfield',
              '#title' => t('Name'),
              '#default_value' => $form_state['input']['names'][$i]['name'],
            );
            $form['names'][$i]['select'] = array(
              '#type' => 'select',
              '#title' => t('Select'),
              '#default_value' => $form_state['input']['names'][$i]['select'],
              '#options'=>array('1'=>'One', '2'=>'Two', '3'=>'Three'),
            );
          }*/
        }
          // add the additional field for a new entry
          $last = count($form_state['input']['names']);
          $form['names'][$last] = array('#type' => 'textfield','#title' => t('NEW'),);
          /*$form['names'][$last]['name'] = array(
              '#type' => 'textfield',
              '#title' => t('Name'),
          );
          $form['names'][$last]['select'] = array(
              '#type' => 'select',
              '#title' => t('Select'),
              '#options'=>array('1'=>'One', '2'=>'Two', '3'=>'Three'),
          );*/
        }

        $form['submit'] = array(
          '#type' => 'submit',
          '#value' => t('Submit'),
        );
        $form['#submit'][] = 'my_form_add_more_submit';

        return $form;
    }

    function ajax_simplest_callback($form, &$form_state) {
        return $form['names'];
    }

    function my_form_add_more_submit($form, &$form_state) {
        print_r($form_state['values']);
        exit();
    }