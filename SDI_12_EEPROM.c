#include <avr/eeprom.h>
#define NUMCHANNELS 1 //specific for Light Sensor

//determine how to automate uuid selection
#define UUID1 53
#define UUID2 31

//We declare the struct that will contain our EEPROM settings
typedef struct {
  char uuid[2];
  char name[30];
  uint8_t nameLength;
  char numChannels;
  float transforms[NUMCHANNELS][2];//numChannels x 2
  char writable[NUMCHANNELS];
  char units[NUMCHANNELS][25];

} settings_t;

settings_t LightEEPSettings EEMEM = { uuid:{UUID1,UUID2},
                                             name:{'5','2'},
									         nameLength:11,
                                             numChannels:NUMCHANNELS,
                                             transforms:{{1.0,0.0}},
                                             writable:{0},
                                             units:{{'l','b'}}  };
