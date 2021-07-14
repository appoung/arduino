#include <SoftwareSerial.h>

SoftwareSerial BTSerial(4, 5);   //bluetooth module Tx:Digital 2 Rx:Digital 3

void setup() {
  Serial.begin(115200);
  BTSerial.begin(115200);
  Serial.println("ATcommand");  //ATcommand Start
}

void loop() {
  if (BTSerial.available())
    Serial.write(BTSerial.read());
  if (Serial.available())
    BTSerial.write(Serial.read());
}
