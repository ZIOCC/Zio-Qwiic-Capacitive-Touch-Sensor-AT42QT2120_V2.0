
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
  touchWheel.begin();
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(qtouch.eventAvailable())
  {
    //Serial.println("TOUCHING...");
//    Serial.println(qtouch.getDetectThreshold(0));
//    Serial.println(qtouch.getDetectionIntegrator());
   
//    for(uint8_t i=5;i<12;i++)
//    {
//      Serial.print("Key");
//      Serial.print(i);
//      Serial.print(": " );
//      Serial.println(qtouch.isKeyPressed(i));
//      }
//    for(uint8_t i=0;i<3;i++)
//    {
//      Serial.print("Key");
//      Serial.print(i);
//      Serial.print(": " );
//      Serial.println(qtouch.isKeyPressed(i));
//      }
    digitalWrite(13,HIGH);
    //Gather touch wheel events
    touchWheel.update();

    uint8_t P=touchWheel.getSliderPosition();
      Serial.println("TOUCHING...");
      Serial.println(P);
      
//    if (touchWheel.isButtonReleased(TouchWheel::Direction::Top))
//    {
//      Serial.println("Top");
//    }  
//    if (touchWheel.isButtonReleased(TouchWheel::Direction::Bottom))
//    {
//      Serial.println("Bottom");
//    }
//    if (touchWheel.isButtonReleased(TouchWheel::Direction::Left))
//    {
//      Serial.println("Left");
//    }  
//    if (touchWheel.isButtonReleased(TouchWheel::Direction::Right))
//    {
//      Serial.println("Right");
//    }
  
  //delay(200);
  }
  digitalWrite(13,LOW);
}
