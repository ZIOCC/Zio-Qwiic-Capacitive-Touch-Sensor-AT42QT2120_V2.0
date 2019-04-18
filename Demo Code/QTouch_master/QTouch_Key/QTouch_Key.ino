
#include "Appfruits_QTouch.h"
#include "TouchWheel.h"

Appfruits_QTouch qtouch = Appfruits_QTouch();
TouchWheel touchWheel(&qtouch);

void setup() {
  // put your setup code here, to run once:
  //Initialize Serial
  Serial.begin(115200);
  Serial.println("QTouch test");
  //Initialize I2C
  Wire.begin();
  qtouch.begin();
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(qtouch.eventAvailable())
  {
    Serial.println("TOUCHING...");
   
    for(uint8_t i=0;i<12;i++)
    {
      Serial.print("Key");
      Serial.print(i);
      Serial.print(": " );
      Serial.println(qtouch.isKeyPressed(i));
      }
    digitalWrite(13,HIGH);

  }
  digitalWrite(13,LOW);
}

