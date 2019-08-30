#include <FastLED.h>    // fast LED library
#include <DMXSerial.h>
#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;

// How many leds are in the strip?
#define NUM_LEDS 132

// Data pin that led data will be written out over
#define DATA_PIN 3

// Clock pin only needed for SPI based chipsets when not using hardware SPI
#define CLOCK_PIN 13

// This is an array of leds.  One item for each led in your strip.
CRGB leds[NUM_LEDS];

unsigned long currentMillis;
long previousMillis = 0;    // set up timers
long interval = 10;        // time constant for timers

int ch19 = 0; // mouth
int mouthLevelPrev = 0;
int mouthLevel = 0;

int ch18 = 0; // eyes
int eyesLevelPrev = 0;
int eyesLevel = 0;

int ch17;
int ch16;
int ch15;
int ch17Filtered;
int ch16Filtered;
int ch15Filtered;


void setup() {    
      FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, BGR>(leds, NUM_LEDS);
      
      DMXSerial.init(DMXReceiver);
      pinMode(6, OUTPUT);  // has to be enabled for the library to work for some reason

      servo1.attach(37);
      servo2.attach(39);
      servo3.attach(41);

      servo1.writeMicroseconds(1500);
      servo2.writeMicroseconds(1500);
      servo3.writeMicroseconds(1500);
      
      Serial.begin(115200);
          
}


void loop() {

      currentMillis = millis();
      if (currentMillis - previousMillis >= 10) {  // start timed event
        
          previousMillis = currentMillis;
        
              //**** MOUTH ****
        
              ch19 = DMXSerial.read(19);    
            
              if (ch19 == 0) {
                mouthLevel = 0;
              }  
              if (ch19 > 0 && ch19 <= 42 ) {
                mouthLevel = 1;
              }  
              else if (ch19 > 42 && ch19 <= 84 ) {
                mouthLevel = 2;
              }  
              else if (ch19 > 84 && ch19 <= 126 ) {
                mouthLevel = 3;
              }
              else if (ch19 > 126 && ch19 <= 168 ) {
                mouthLevel = 4;
              }
              else if (ch19 > 168 && ch19 <= 210 ) {
                mouthLevel = 5;
              }
              else if (ch19 > 210) {
                mouthLevel = 6;
              }  

              //*********************************
              
              if (mouthLevel != mouthLevelPrev) {   // check the level is different
             
                    if (mouthLevel == 0){
                      mouth(0);
                    }
                    else if (mouthLevel == 1){
                      mouth(0);  //clear
                      mouth(1);
                    }
                    else if (mouthLevel == 2){
                      mouth(0); // clear
                      mouth(2);
                    }
                    else if (mouthLevel == 3){
                      mouth(0); // clear
                      mouth(3);
                    }
                    else if (mouthLevel == 4){
                      mouth(0); // clear
                      mouth(4);
                    }
                    else if (mouthLevel == 5){
                      mouth(0); // clear
                      mouth(5);
                    }
                    else if (mouthLevel == 6){
                      mouth(0); // clear
                      mouth(6);
                    }
                  }
        
              mouthLevelPrev = mouthLevel;    // bookmark the level so we can see if it's different
        
              //*** EYES *** 
        
              ch18 = DMXSerial.read(18); 
        
              if (ch18 == 0) {
                  eyesLevel = 0;
              }
              else if (ch18 >= 1 && ch18 <=5){
                  eyesLevel = 1;
              }
              else if (ch18 >= 6 && ch18 <=10){
                  eyesLevel = 2;
              }
              else if (ch18 >= 11 && ch18 <=15){
                  eyesLevel = 3;
              }

              //****

              else if (ch18 >= 96 && ch18 <=100){
                  eyesLevel = 20;
              }
              else if (ch18 >= 101 && ch18 <=105){
                  eyesLevel = 21;
              }
              else if (ch18 >= 106 && ch18 <=110){
                  eyesLevel = 22;
              }
              else if (ch18 >= 111 && ch18 <=115){
                  eyesLevel = 23;
              }
              else if (ch18 >= 116 && ch18 <=120){
                  eyesLevel = 24;
              }
              else if (ch18 >= 121 && ch18 <=125){
                  eyesLevel = 25;
              }
              else if (ch18 >= 126 && ch18 <=130){
                  eyesLevel = 26;
              }
              else if (ch18 >= 131 && ch18 <=135){
                  eyesLevel = 27;
              }
              else if (ch18 >= 136 && ch18 <=140){
                  eyesLevel = 28;
              }
              else if (ch18 >= 141 && ch18 <=145){
                  eyesLevel = 29;
              }
              else if (ch18 >= 146 && ch18 <=150){
                  eyesLevel = 30;
              }
              else if (ch18 >= 151 && ch18 <=155){
                  eyesLevel = 31;
              }
              else if (ch18 >= 156 && ch18 <=160){
                  eyesLevel = 32;
              }
              else if (ch18 >= 161 && ch18 <=165){
                  eyesLevel = 33;
              }
              else if (ch18 >= 166 && ch18 <=170){
                  eyesLevel = 34;
              }
              else if (ch18 >= 174 && ch18 <=175){
                  eyesLevel = 35;
              }
              else if (ch18 >= 176 && ch18 <=180){
                  eyesLevel = 36;
              }
              else if (ch18 >= 181 && ch18 <=185){
                  eyesLevel = 37;
              }
              else if (ch18 >= 186 && ch18 <=190){
                  eyesLevel = 38;
              }
              else if (ch18 >= 191 && ch18 <=195){
                  eyesLevel = 39;
              }
              else if (ch18 >= 196 && ch18 <=200){
                  eyesLevel = 40;
              }
              else if (ch18 >= 202 && ch18 <=205){
                  eyesLevel = 41;
              }
              else if (ch18 >= 206 && ch18 <=210){
                  eyesLevel = 42;
              }
              else if (ch18 >= 211 && ch18 <=215){
                  eyesLevel = 43;
              }
              

              //******************************
        
                  if (eyesLevel != eyesLevelPrev) {       // the eye level is different, clear the screen and output the new data
                    
                        if (eyesLevel == 0) {
                          eyes(0);
                        }
                        else if (eyesLevel == 1) {
                          eyes(0);
                          eyes(1);
                        }
                        else if (eyesLevel == 2) {
                          eyes(0);
                          eyes(2);
                        }
                        else if (eyesLevel == 3) {
                          eyes(0);
                          eyes(3);
                        }
                        //******************
                        else if (eyesLevel == 20) {
                          eyes(0);
                          eyes(20);
                        }
                        else if (eyesLevel == 21) {
                          eyes(0);
                          eyes(21);
                        }
                        else if (eyesLevel == 22) {
                          eyes(0);
                          eyes(22);
                        }
                        else if (eyesLevel == 23) {
                          eyes(0);
                          eyes(23);
                        }
                        else if (eyesLevel == 24) {
                          eyes(0);
                          eyes(24);
                        }
                        else if (eyesLevel == 25) {
                          eyes(0);
                          eyes(25);
                        }
                        else if (eyesLevel == 26) {
                          eyes(0);
                          eyes(26);
                        }
                        else if (eyesLevel == 27) {
                          eyes(0);
                          eyes(27);
                        }
                        else if (eyesLevel == 28) {
                          eyes(0);
                          eyes(28);
                        }
                        else if (eyesLevel == 29) {
                          eyes(0);
                          eyes(29);
                        }
                        else if (eyesLevel == 30) {
                          eyes(0);
                          eyes(30);
                        }
                        else if (eyesLevel == 31) {
                          eyes(0);
                          eyes(31);
                        }
                        else if (eyesLevel == 32) {
                          eyes(0);
                          eyes(32);
                        }
                        else if (eyesLevel == 33) {
                          eyes(0);
                          eyes(33);
                        }
                        else if (eyesLevel == 34) {
                          eyes(0);
                          eyes(34);
                        }
                        else if (eyesLevel == 35) {
                          eyes(0);
                          eyes(35);
                        }
                        else if (eyesLevel == 36) {
                          eyes(0);
                          eyes(36);
                        }
                        else if (eyesLevel == 37) {
                          eyes(0);
                          eyes(37);
                        }
                        else if (eyesLevel == 38) {
                          eyes(0);
                          eyes(38);
                        }
                        else if (eyesLevel == 39) {
                          eyes(0);
                          eyes(39);
                        }
                        else if (eyesLevel == 40) {
                          eyes(0);
                          eyes(40);
                        }
                        else if (eyesLevel == 41) {
                          eyes(0);
                          eyes(41);
                        }
                        else if (eyesLevel == 42) {
                          eyes(0);
                          eyes(42);
                        }
                        else if (eyesLevel == 43) {
                          eyes(0);
                          eyes(43);
                        }
                  }
        
              eyesLevelPrev = eyesLevel;               // bookmark the previous level to check it's different
        
              //*** SERVOS ****
        
              ch17 = DMXSerial.read(17); 
              ch16 = DMXSerial.read(16); 
              ch15 = DMXSerial.read(15);
        
              ch17 = map(ch17,0,255,700,2300);
              ch16 = map(ch16,0,255,700,2300);
              ch15 = map(ch15,0,255,2600,700);      
        
              ch15Filtered = (float) filter(ch15, ch15Filtered, 30);
              ch16Filtered = (float) filter(ch16, ch16Filtered, 30);
              ch17Filtered = (float) filter(ch17, ch17Filtered, 30);
             
              servo3.writeMicroseconds(ch17Filtered);      
              servo2.writeMicroseconds(ch16Filtered);      
              servo1.writeMicroseconds(ch15Filtered);

      } // end of timed event


}

// filter function

float filter(float lengthOrig, float currentValue, int filter) {
  float lengthFiltered =  (lengthOrig + (currentValue * filter)) / (filter + 1);
  return lengthFiltered;  
}
      


        





      









