#include <Servo.h>
#include <DMXSerial.h>

Servo servo1;     // hand
Servo servo2;     // wrist

int ch13;
int ch14;
int hall;
int hallStartup;
int flag = 0;
int hand = 0;
float wrist = 90;
float wristFiltered = 90;

unsigned long currentMillis;
long previousMillis = 0;    // set up timers

void setup () {
 
  DMXSerial.init(DMXReceiver);
  
  pinMode(A0, INPUT);
  
  servo1.attach(5);   // hand
  servo2.attach(6);   // wrist

  servo1.write(hand);   // hand
  servo2.write(90);   // wrist

  hallStartup = analogRead(A0);

  pinMode(13, OUTPUT);
    
}

void loop() {

      currentMillis = millis();
      if (currentMillis - previousMillis >= 10) {  // start timed event        
              previousMillis = currentMillis;      // reset the clock

              /*   // serial test code
              if (Serial.available()) {
                  char c = Serial.read();        
                  if (c == 'a') {
                      flag = 1;
                  }
                  if (c == 'b') {
                      flag = 2;
                  }
                }
                */

              ch13 = DMXSerial.read(13);    // read DMX channels
              ch14 = DMXSerial.read(14);

              // operate gripper

              if (ch13 < 100) {
                flag = 2;     //  hand is open
                digitalWrite(13, LOW);
              }

              else if (ch13 > 100) {
                flag = 1;     //  hand is closed
                digitalWrite(13, HIGH);
              }

              hall = analogRead(A0) - hallStartup;

              if (flag == 1 && hall > -300) {
                  hand = hand + 1;
                  hand = constrain(hand, 0,180);  
              }
              else if (flag == 2) {
                  hand = 0;
              }

              servo1.write(hand);   // hand servo write

              // operate wrist

              wrist = map(ch14,0,255,1000,2000);
              wristFiltered = filter(wrist, wristFiltered, 20);

              servo2.writeMicroseconds(wristFiltered);   // wrist servo write              
              
          

      }   // end of timed event

}

float filter(float prevValue, float currentValue, int filter) {  
  float lengthFiltered =  (prevValue + (currentValue * filter)) / (filter + 1);  
  return lengthFiltered;  
}

