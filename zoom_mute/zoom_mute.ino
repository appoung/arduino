int touchSensor = 8;  // 터치센서 핀 설정
int led = 13;
void setup() {
   Serial.begin(9600); 
   pinMode(touchSensor, INPUT);
   pinMode(13, OUTPUT);

}

void loop() {
  int touchValue = digitalRead(touchSensor);
  if (touchValue == HIGH){      
    Serial.println("TOUCHED");
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
}
}
