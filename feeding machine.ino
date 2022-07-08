#include <SoftwareSerial.h>
#include <Servo.h>
Servo myservo;

SoftwareSerial swSerial(2,3);
void setup()
{
  swSerial.begin(9600);
  myservo.attach(9);
  pinMode(13, OUTPUT);
}


void loop( ) {
  if ( swSerial.available() ) {
    char cmd = (char) swSerial.read();
    if(cmd == '1') {
      tone(8, 392, 500);
      delay(500);
      noTone(8);
      digitalWrite(13, HIGH);
      myservo.write(120); 
    } else if(cmd == '0') {
        digitalWrite(13, LOW);
        myservo.write(0);
    }
 }
}

