// ORANGE ROBOT

#include <DMXSerial.h>    // libary is using Serial 1 on Arduino MEGA

int cha;
int chb;
int chc;
int chd;
int che;
int chf;
int chg;
int chh;
int chi;
int chj;

int ch1 = 0;
int ch2 = 0;
int ch3 = 0;
int ch4 = 0;
int ch5 = 0;
int ch6 = 0;
int ch7 = 0;
int ch8 = 0;
int ch9 = 0;
int ch10 = 0;
int ch11 = 0;
int ch12 = 0;


int ch1Prev;
int ch2Prev;
int ch3Prev;
int ch4Prev;
int ch5Prev;
int ch6Prev;
int ch7Prev;
int ch8Prev;
int ch9Prev;
int ch10Prev;
int ch11Prev;
int ch12Prev;

int switch1;

void setup() {
  
  DMXSerial.init(DMXController);        // libary is using Serial 1 on Arduino MEGA
  Serial.begin(115200);

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT); 
  pinMode(A3, INPUT);
  pinMode(A4, INPUT); 
  pinMode(A5, INPUT);
  pinMode(A6, INPUT);
  pinMode(A7, INPUT); 
  pinMode(A8, INPUT);
  pinMode(A9, INPUT); 
  pinMode(A10, INPUT);
  pinMode(A11, INPUT); 

  pinMode(52, INPUT_PULLUP);
 
} // setup


// loop through the rainbow colors 
void loop() {

  cha = analogRead(A0);
  chb = analogRead(A1);
  chc = analogRead(A2);
  chd = analogRead(A3);
  che = analogRead(A4);
  chf = analogRead(A5);
  chg = analogRead(A6);
  chh = analogRead(A7);
  chi = analogRead(A8);
  chj = analogRead(A9);
  
  //*** sort out abs/rib motion and divide into the two actuators
  chb = (chb - 465)*2;
  cha = (cha-512)*2;
  ch9 = chb - cha;
  ch10 = chb + cha;
  ch9 = constrain(ch9,0,255);
  ch10 = constrain(ch10,0,255);  
  

  //*** the other channels

  chc = chc-550;                // arms outwards
  chc = map(chc,0,380,0,255); 
  ch8 = constrain(chc,0,255);
  chd = chd-516;
  chd = map(chd,0,380,0,255); 
  ch7 = constrain(chd,0,255);

  che = (che-856)*-1;           // arms forward
  che = map(che,0,700,0,255);
  ch6 = constrain(che,0,255);
  
  chf = (chf-865)*-1;       
  chf = map(chf,0,700,0,255);
  ch5 = constrain(chf,0,255);

  chg = (chg - 555);            // arms rotation
  chg = map(chg,-200,200,0,255);
  ch3 = constrain(chg,0,255);
  
  chh = (chh - 500);
  chh = map(chh,-200,200,0,255);
  ch1 = constrain(chh,0,255);

  chi = chi - 200;
  chi = map(chi,0,300,0,255);
  ch4 = constrain(chi,0,255);


  chj = chj - 176;
  chj = map(chj,0,300,0,255);
  ch2 = constrain(chj,0,255);

  switch1 = digitalRead(52);       // 'ZERO switch' 

  if (switch1 == 0) {
      ch1 = 0;
      ch2 = 0;
      ch3 = 0;
      ch4 = 0;
      ch5 = 0;
      ch6 = 0;
      ch7 = 0;
      ch8 = 0;
      ch9 = 120;
      ch10 = 120;    
  }
  

   //*** write DMX channels out

  if (ch1 != ch1Prev) {
    DMXSerial.write(1, ch1);
  }
  ch1Prev = ch1; 

  if (ch2 != ch2Prev) {
    DMXSerial.write(2, ch2);
  }
  ch2Prev = ch2; 

  if (ch3 != ch3Prev) {
    DMXSerial.write(3, ch3);
  }
  ch3Prev = ch3; 
  
  if (ch4 != ch4Prev) {
    DMXSerial.write(4, ch4);
  }
  ch4Prev = ch4; 

  if (ch5 != ch5Prev) {
    DMXSerial.write(5, ch5);
  }
  ch5Prev = ch5;  

  if (ch6 != ch6Prev) {
    DMXSerial.write(6, ch6);
  }
  ch6Prev = ch6;

  if (ch7 != ch7Prev) {
    DMXSerial.write(7, ch7);
  }
  ch7Prev = ch7;

  if (ch8 != ch8Prev) {
    DMXSerial.write(8, ch8);
  }
  ch8Prev = ch8;

  if (ch9 != ch9Prev) {
    DMXSerial.write(9, ch9);
  }
  ch9Prev = ch9;

  if (ch10 != ch10Prev) {
    DMXSerial.write(10, ch10);
  }
  ch10Prev = ch10;



  Serial.print("  1: ");
  Serial.print(ch1);
  Serial.print("  2: ");
  Serial.print(ch2);
  Serial.print("  3: ");
  Serial.print(ch3);
  Serial.print("  4: ");
  Serial.print(ch4);
  Serial.print("  5: ");
  Serial.print(ch5);
  Serial.print("  6: ");
  Serial.print(ch6);
  Serial.print("  7: ");
  Serial.print(ch7);
  Serial.print("  8: ");
  Serial.print(ch8);
  Serial.print("  9: ");
  Serial.print(ch9);
  Serial.print("  10: ");
  Serial.println(ch10);




} // loop

