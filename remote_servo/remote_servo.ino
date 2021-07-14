#include <IRremote.h>

 

int RECV_PIN = 11;

int i = 0;

unsigned long remo = 0;

 

IRrecv irrecv(RECV_PIN);

 

decode_results results;

 

void setup()

{

Serial.begin(9600);

pinMode(13, OUTPUT);

pinMode(2, OUTPUT);

irrecv.enableIRIn(); // Start the receiver

}

 

void loop() {

if (irrecv.decode(&results)) {

 

//Serial.println(results.value, HEX);

remo = results.value;

Serial.println(remo, HEX);

if(remo == 0xFFA25D)

{

digitalWrite(13, HIGH);

for(i=0 ; i < 99 ; i++ ) // 원하는 횟수 반복

{

digitalWrite(2, HIGH); // 2번 핀으로 켜짐

delayMicroseconds(1500); // 1.5ms 동안의 시간을 지연

digitalWrite(2, LOW); // 2번 핀으로 꺼짐

delay(5); // 5ms 동안 지연

}

// delay(1000); // 1초 동안 동작 멈춤

 

}

else if(remo == 0xFFE21D)

{

digitalWrite(13, LOW);

for(i=0 ; i < 99 ; i++ )// 원하는 횟수 반복

{

digitalWrite(2, HIGH); // 2번 핀으로 켜짐

delayMicroseconds(700); // 0.7ms 동안의 시간을 지연

digitalWrite(2, LOW); // 2번 핀으로 꺼짐

delay(5); // 5ms 동안 지연

}

//delay(1000); // 1초 동안 동작 멈춤

 

}

irrecv.resume(); // Receive the next value

}

}
