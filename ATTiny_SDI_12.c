/*
  This is an example use case of the SDI-12 ported library.

*/
#include <avr/io.h>
#include <util/delay.h>
#include "SDI12.h"

#define MAX_PAYLOAD_LENGTH 256

/* 
  SDI-12 Commands

  Address is set to '0' by default
*/
char set_default_measurements_str[8] = {'0','X','M','=','G','H','!',0x0};
char request_for_measurements_str[4] = {'0','M','!',0x0};
char read_measurements_str[5]        = {'0','D','0','!',0x0};

/* 
  SDI-12 Available Commands
*/
void    set_measurements      ( SDI12 * sdi12 );
void    request_measurements  ( SDI12 * sdi12 );
uint8_t read_measurements     ( SDI12 * sdi12 , uint8_t * payload );

int main(void)
{
	  
  uint8_t sdi_len = 0;
	uint8_t temp_payload[MAX_PAYLOAD_LENGTH];

  SDI12 sdi12(0);
  
    
  /*Initialize SDI-12 driver */
  sdi12.begin();
  
  /*Set default measurement set*/
  set_measurements(&sdi12);
  
  /*Make Request*/          
	do {
      request_measurements(&sdi12);
		  sdi_len = read_measurements(&sdi12,temp_payload);
      if ( sdi_len > 0 ) {
        // temp_payload contains response
      }
      
  } while ( 1 );

}

/*
    SDI-12 :: Used to set default measurements we require

*/
void set_measurements ( SDI12 * sdi12 ) {
  sdi12->sendCommand(set_default_measurements_str);
  
  _delay_ms(1000); // delay 1 second
  while(sdi12->available()){sdi12->read();} // ignore response
  sdi12->flush();
  _delay_ms(300);
  
}


/*
    SDI-12 :: Request measurements from SDI-12 (Prepare)
*/
void request_measurements ( SDI12 * sdi12 ) {
  sdi12->sendCommand(request_for_measurements_str);
  
  // Delay for 1 second to receive data
  _delay_ms(1000);
  
  while(sdi12->available()){sdi12->read();}
  sdi12->flush();
  
  _delay_ms(300);
}

/*
    SDI-12 :: Read measurements from SDI-12 (After a delay)
*/
uint8_t read_measurements ( SDI12 * sdi12 , uint8_t * payload ) {
  
  sdi12->sendCommand(read_measurements_str);
  _delay_ms(1000);
  uint8_t  p_index = 0;
  
  while(sdi12->available() && p_index < MAX_PAYLOAD_LENGTH ){
    payload[p_index++] = sdi12->read();
  }
  sdi12->flush();
  
  _delay_ms(300);
  return p_index-1;
}




