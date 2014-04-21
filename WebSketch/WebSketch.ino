#include <Adafruit_CC3000.h>
#include <SPI.h>
#include "utility/debug.h"
#include "utility/socket.h"
//#include "Arduino.h"


#define ADAFRUIT_CC3000_IRQ   2 
#define ADAFRUIT_CC3000_VBAT  9
#define ADAFRUIT_CC3000_CS    10

Adafruit_CC3000 cc3000 = Adafruit_CC3000(ADAFRUIT_CC3000_CS, ADAFRUIT_CC3000_IRQ, ADAFRUIT_CC3000_VBAT, SPI_CLOCK_DIVIDER); // you can change this clock speed

#define WLAN_SSID       "SSID"           // cannot be longer than 32 characters!
#define WLAN_PASS       "PASS"

#define WLAN_SECURITY   WLAN_SEC_WPA2

#define LISTEN_PORT           80    

Adafruit_CC3000_Server fluxServer(LISTEN_PORT);

boolean matched = false;
 
 //Pin connected to ST_CP of 74HC595
int latchPin = 6;
//Pin connected to SH_CP of 74HC595
int clockPin = 7;
////Pin connected to DS of 74HC595
int dataPin = 5;
byte dataArray[10];
int fluxDelay = 500;
byte data;
long lastFlux;


void setup(void)
{
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
  Serial.begin(115200);
  initFlux();
  initNet();
}

void loop(void)
{
  fluxTheCapacitor();
  checkNetwork();
}



