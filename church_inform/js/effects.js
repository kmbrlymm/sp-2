if (Drupal.jsEnabled) {
  $(document).ready(function () {
    $('div.show-hide-text').click(function() {
      $('#names-fieldset-wrapper').slideToggle();  
    });
    Console.log("WEW");
  });
}