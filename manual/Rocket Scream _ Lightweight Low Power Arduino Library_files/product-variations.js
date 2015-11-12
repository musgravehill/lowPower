/* 
 * Controls the form display when variation selection changes
 */
jQuery( document ).bind( 'found_variation', function( event, variation ) {
 
  var email_form = jQuery( '#bolder_alerts_outer' );
  if( variation.is_in_stock ) {
    email_form.hide();
  } else {
    email_form.show();
  }

} );