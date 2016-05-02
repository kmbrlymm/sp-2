if (Drupal.jsEnabled) {
  $(document).ready(function () {
    $('div#main-names-fieldset-wrapper').find('div.show-hide-text').hide().end().click(function() {
      $(this).parents().children('div#names-fieldset-wrapper').slideToggle();  
    });
  });
}