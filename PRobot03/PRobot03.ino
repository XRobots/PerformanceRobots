#include <ODriveArduino.h>
#include <PID_v1.h>  
#include <TeensyDMX.h>
namespace teensydmx = ::qindesign::teensydmx;

// Create the DMX receiver on Serial1.
teensydmx::Receiver dmxRx{Serial1};

double Pk1 = 1;  
double Ik1 = 0;
double Dk1 = 0;
double Setpoint1, Setpoint1Filtered, Input1, Output1, Output1a;    // PID variables position

PID PID1(&Input1, &Output1, &Setpoint1, Pk1, Ik1 , Dk1, DIRECT);

double Pk2 = 1;  
double Ik2 = 0;
double Dk2 = 0;
double Setpoint2, Setpoint2Filtered, Input2, Output2, Output2a;    // PID variables position

PID PID2(&Input2, &Output2, &Setpoint2, Pk2, Ik2 , Dk2, DIRECT);

double Pk3 = 1;  
double Ik3 = 0;
double Dk3 = 0;
double Setpoint3, Setpoint3Filtered, Input3, Output3, Output3a;    // PID variables position

PID PID3(&Input3, &Output3, &Setpoint3, Pk3, Ik3 , Dk3, DIRECT);

double Pk4 = 1;  
double Ik4 = 0;
double Dk4 = 0;
double Setpoint4, Setpoint4Filtered, Input4, Output4, Output4a;    // PID variables position

PID PID4(&Input4, &Output4, &Setpoint4, Pk4, Ik4 , Dk4, DIRECT);

// Printing with stream operator
template<class T> inline Print& operator <<(Print &obj,     T arg) { obj.print(arg);    return obj; }
template<>        inline Print& operator <<(Print &obj, float arg) { obj.print(arg, 4); return obj; }

//ODrive Object
ODriveArduino odrive1(Serial2);   // arm outwards
ODriveArduino odrive2(Serial3);   // ribs
ODriveArduino odrive3(Serial4);   // smaller arm motors

unsigned long currentMillis;

long previousMillis = 0;    // set up timers
long interval = 10;        // time constant for timers
unsigned long count;

int requested_state; // required for Odrive init

int loopTime;
int previousLooptime;

unsigned long previousSafetyMillis;

int switch1;
int switch2;

#define encoder0PinA 33      // encoder 0
#define encoder0PinB 34
#define encoder1PinA 35      // encoder 1
#define encoder1PinB 36
#define encoder2PinA 37      // encoder 2
#define encoder2PinB 38
#define encoder3PinA 39      // encoder 3
#define encoder3PinB 14

volatile long encoder0Pos = 0;    // encoder 0
volatile long encoder1Pos = 0;    // encoder 1
volatile long encoder2Pos = 0;    // encoder 2
volatile long encoder3Pos = 0;    // encoder 3

int read0;
int read1;
int read2;
int read3;
int read4;
char ident;

long BRArmRight;
long BRArmLeft;
long ShoulderRight;
long ShoulderLeft;
long AbLeft;
long AbRight;

long BRArmRightFiltered;
long BRArmLeftFiltered;
long ShoulderRightFiltered;
long ShoulderLeftFiltered;
long AbLeftFiltered;
long AbRightFiltered;

uint8_t ch1;
uint8_t ch2;
uint8_t ch3;
uint8_t ch4;
uint8_t ch5;
uint8_t ch6;
uint8_t ch7;
uint8_t ch8;
uint8_t ch9;
uint8_t ch10;

int ch1a;
int ch2a;
int ch3a;
int ch4a;
int ch5a;
int ch6a;
int ch7a;
int ch8a;
int ch9a;
int ch10a;

// ****************** SETUP ******************************

void setup() {  

    // initialize serial communication
    Serial.begin(115200);

    // Start the receiver
    dmxRx.begin();

    //ODrive serial ports
    Serial2.begin(115200);
    Serial3.begin(115200);
    Serial4.begin(115200);

    

    pinMode(15, INPUT_PULLUP);    // switch
    pinMode(16, INPUT_PULLUP);    // switch

    /*
    pinMode(33, INPUT_PULLUP);    // encoder 0
    pinMode(34, INPUT_PULLUP);
    pinMode(35, INPUT_PULLUP);    // encoder 1
    pinMode(36, INPUT_PULLUP);
    pinMode(37, INPUT_PULLUP);    // encoder 2
    pinMode(38, INPUT_PULLUP);
    pinMode(39, INPUT_PULLUP);    // encoder 3
    pinMode(14, INPUT_PULLUP);

    */

    pinMode(2, OUTPUT);           // motors
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(6, OUTPUT);

    pinMode(29, OUTPUT);
    pinMode(30, OUTPUT);
    pinMode(23, OUTPUT);
    pinMode(22, OUTPUT); 

    digitalWrite(2, LOW);         // turn off all motors
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(6, LOW);

    digitalWrite(29, LOW);
    digitalWrite(30, LOW);
    digitalWrite(23, LOW);
    digitalWrite(22, LOW);
    
    attachInterrupt(33, doEncoderA, RISING);        // encoder 0
    attachInterrupt(34, doEncoderB, RISING); 
    attachInterrupt(35, doEncoderC, RISING);        // encoder 1
    attachInterrupt(36, doEncoderD, RISING);  
    attachInterrupt(37, doEncoderE, RISING);        // encoder 2
    attachInterrupt(38, doEncoderF, RISING); 
    attachInterrupt(39, doEncoderG, RISING);        // encoder 3
    attachInterrupt(14, doEncoderH, RISING); 
    
    PID1.SetMode(AUTOMATIC);              
    PID1.SetOutputLimits(-255, 255);
    PID1.SetSampleTime(10);

    PID2.SetMode(AUTOMATIC);              
    PID2.SetOutputLimits(-255, 255);
    PID2.SetSampleTime(10);

    PID3.SetMode(AUTOMATIC);              
    PID3.SetOutputLimits(-255, 255);
    PID3.SetSampleTime(10);

    PID4.SetMode(AUTOMATIC);              
    PID4.SetOutputLimits(-255, 255);
    PID4.SetSampleTime(10);

}

// ********************* MAIN LOOP *******************************

void loop() {  
      
        currentMillis = millis();
        if (currentMillis - previousMillis >= 10) {  // start timed event
          
        previousMillis = currentMillis;       

        if (Serial.available()>2) {  // check for enough serial data
              // read the incoming byte:
              read0 = Serial.parseInt();   
              ident = Serial.read();
              // DC Brushed
              if (ident == 'a') {
                read1 = read0;
              }
              else if (ident == 'b') {
                read2 = read0;
              }
              else if (ident == 'c') {
                read3 = read0;
              }
              else if (ident == 'd') {
                read4 = read0;
              }
              // ODrives
              else if (ident == 'e') {
                ODriveGo1();
              }
              else if (ident == 'f') {
                ODriveGo2();
              }
              else if (ident == 'g') {
                ODriveGo3();
              }
              else if (ident == 'h') {
                ODriveGo4();
              }
              else if (ident == 'i') {
                ODriveGo5();
              }
              else if (ident == 'j') {
                ODriveGo6();
              }
              else if (ident == 'k') {
                ODriveGo7();
              }
              else if (ident == 'l') {
                ODriveGo8();
              }
              else if (ident == 'm') {
                ODriveGo9();
              }
              
        }

  

        loopTime = currentMillis - previousLooptime;
        //Serial.print("time: ");
        //Serial.print(loopTime);
        //Serial.print("\t");
        previousLooptime = currentMillis; 

        switch1 = digitalRead(15);
        switch2 = digitalRead(16);

        if (switch2 == 0) {     // init Odrive
            OdriveInit();
            encoder0Pos = 0;    // encoder 0
            encoder1Pos = 0;    // encoder 1
            encoder2Pos = 0;    // encoder 2
            encoder3Pos = 0;    // encoder 3

        }

        // get DMX values

        ch1 = dmxRx.get(1);
        ch2 = dmxRx.get(2);
        ch3 = dmxRx.get(3);
        ch4 = dmxRx.get(4);
        ch5 = dmxRx.get(5);
        ch6 = dmxRx.get(6);
        ch7 = dmxRx.get(7);
        ch8 = dmxRx.get(8);
        ch9 = dmxRx.get(9);
        ch10 = dmxRx.get(10);

        ch3a = map(ch1,0,255,0,6000);      // DC arm left 1
        ch4a = map(ch2,0,255,0,4500);      // DC arm left 2
        ch1a = map(ch3,0,255,0,-6000);       // DC arm right 1
        ch2a = map(ch4,0,255,0,-4500);       // DC arm right 2
        
        ch5a = map(ch5,0,255,0,35000);      // BR arm left
        ch6a = map(ch6,0,255,0,-35000);     // BR arm right
        ch7a = map(ch7,0,255,0,-350000);       // Shoulder right
        ch8a = map(ch8,0,255,0,-350000);       // shoulder left
        ch9a = map(ch9,0,255,0,-200000)+100000;       // Abs left
        ch10a = map(ch10,0,255,0,-200000)+100000;     // Abs right

        // Brushless Motors

        BRArmLeftFiltered = filter(ch5a, BRArmLeftFiltered, 40);
        BRArmRightFiltered = filter(ch6a, BRArmRightFiltered, 40);

        ShoulderRightFiltered = filter(ch7a, ShoulderRightFiltered, 40);
        ShoulderLeftFiltered = filter(ch8a, ShoulderLeftFiltered, 40);

        AbLeftFiltered = filter(ch9a, AbLeftFiltered, 50);
        AbRightFiltered = filter(ch10a, AbRightFiltered, 50);

        odrive3.SetPosition(0, BRArmLeftFiltered);        // arms forward | backwards
        odrive3.SetPosition(1, BRArmRightFiltered);

        odrive1.SetPosition(0, ShoulderLeftFiltered);     // Shoulder in | out
        odrive1.SetPosition(1, ShoulderRightFiltered);

        odrive2.SetPosition(0, AbLeftFiltered);   // Abs
        odrive2.SetPosition(1, AbRightFiltered); 


        // DC Motor PIDs etc

        Input1 = encoder0Pos;
        Setpoint1Filtered = filter(ch1a, Setpoint1Filtered, 40);        
        Setpoint1 = Setpoint1Filtered;   
        //Setpoint1 = read1;      
        PID1.Compute();        

        Input2 = encoder1Pos;
        Setpoint2Filtered = filter(ch2a, Setpoint2Filtered, 40);        
        Setpoint2 = Setpoint2Filtered;     
        //Setpoint2 = read2;   
        PID2.Compute();

        Input3 = encoder2Pos;
        Setpoint3Filtered = filter(ch3a, Setpoint3Filtered, 40);        
        Setpoint3 = Setpoint3Filtered;
        //Setpoint3 = read3;        
        PID3.Compute();

        Input4 = encoder3Pos;
        Setpoint4Filtered = filter(ch4a, Setpoint4Filtered, 40);        
        Setpoint4 = Setpoint4Filtered;   
        //Setpoint4 = read4;
        PID4.Compute();


        // ************** motor 1 *****************
        if (Output1 < 0)                                       // decide which way to turn the motor
        {
            Output1a = abs(Output1);
            analogWrite(2, Output1a);                                // set PWM pins 
            analogWrite(3, 0);
        }
        else if (Output1 > 0)                                  // decide which way to turn the motor
        { 
            Output1a = abs(Output1);
            analogWrite(3, Output1a);  
            analogWrite(2, 0);
        } 
        else
        {
            analogWrite(2, 0);  
            analogWrite(3, 0);
        } 

        // ************** motor 2 *****************
        if (Output2 < 0)                                       // decide which way to turn the motor
        {
            Output2a = abs(Output2);
            analogWrite(4, Output2a);                                // set PWM pins 
            analogWrite(6, 0);
        }
        else if (Output2 > 0)                                  // decide which way to turn the motor
        { 
            Output2a = abs(Output2);
            analogWrite(6, Output2a);  
            analogWrite(4, 0);
        } 
        else
        {
            analogWrite(4, 0);  
            analogWrite(6, 0);
        } 


        // ************** motor 3 *****************
        if (Output3 < 0)                                       // decide which way to turn the motor
        {
            Output3a = abs(Output3);
            analogWrite(29, Output3a);                                // set PWM pins 
            analogWrite(30, 0);
        }
        else if (Output3 > 0)                                  // decide which way to turn the motor
        { 
            Output3a = abs(Output3);
            analogWrite(30, Output3a);  
            analogWrite(29, 0);
        } 
        else
        {
            analogWrite(29, 0);  
            analogWrite(30, 0);
        } 


        // ************** motor 4 *****************
        if (Output4 < 0)                                       // decide which way to turn the motor
        {
            Output4a = abs(Output4);
            analogWrite(23, Output4a);                                // set PWM pins 
            analogWrite(22, 0);
        }
        else if (Output4 > 0)                                  // decide which way to turn the motor
        { 
            Output4a = abs(Output4);
            analogWrite(22, Output4a);  
            analogWrite(23, 0);
        } 
        else
        {
            analogWrite(23, 0);  
            analogWrite(22, 0);
        } 
          
      
   }     // end of timed event 

 
   
}           // end  of main loop


// filter function

float filter(float lengthOrig, float currentValue, int filter) {
  float lengthFiltered =  (lengthOrig + (currentValue * filter)) / (filter + 1);
  return lengthFiltered;  
}






