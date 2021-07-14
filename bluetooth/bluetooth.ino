#include <SoftwareSerial.h>
//Initial pin number
int bluetoothRX = 4;
int bluetoothTX = 5;
//Define to use bluetooth module
SoftwareSerial ble ( bluetoothTX, bluetoothRX );
void setup() {
  Serial.begin ( 9600 );
  ble.begin ( 9600 );
}
void loop() {
  if ( Serial.available() ) {
    ble.write( Serial.read() );
  }
  if ( ble.available() ) {
    Serial.write( ble.read() );
  }
}
