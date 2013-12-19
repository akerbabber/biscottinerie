/* Sweep
 by BARRAGAN <http://barraganstudio.com> 
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://arduino.cc/en/Tutorial/Sweep
*/ 

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
 
int pos = 0;    // variable to store the servo position 
int mode=0;

int top=A1;
int left=A2;
int bottom=A3;
int right=A4;
int enlight=A5;

int motor1Pin1 = 3;    // pin 2 on L293D
int motor1Pin2 = 6;    // pin 7 on L293D


int v_top=0;
int v_left=0;
int v_bottom=0;
int v_right=0;

int verse=0; 

 
void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  Serial.begin(9600);
   
  // set all the other pins you're using as outputs:
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  
} 
 
void loop() 
{ 
v_top = analogRead(top);
v_left  = analogRead(left);
v_bottom  = analogRead(bottom);
v_right  = analogRead(right);




  // if the switch is high, motor will turn on one direction:
  
  
Serial.print("\t");
Serial.print(mode);
Serial.print("\n");  
Serial.print(v_top);
Serial.print("\n");
Serial.print(v_left);
Serial.print("\n");
Serial.print(v_bottom);
Serial.print("\n");
Serial.print(v_right);
Serial.print("\n");

if (((v_top+v_left+v_bottom+v_right)/4)<500) mode=1;
else mode=0;

if (mode==0) {
    digitalWrite(motor1Pin1, LOW);   // set pin 2 on L293D low
    digitalWrite(motor1Pin2, HIGH);  // set pin 7 on L293D high
 
}
else {
    digitalWrite(motor1Pin1, LOW);   // set pin 2 on L293D low
    digitalWrite(motor1Pin2, LOW);  // set pin 7 on L293D high
}

if (mode==1) {  
if (verse==0)   // goes from 0 degrees to 180 degrees 
  { 
   
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);
    pos += 1;
    if (pos==170) verse=1;
     
  } 
if (verse==1)      // goes from 180 degrees to 0 degrees 
  { 
       
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);
    pos-=1 ;
    if (pos==10) verse=0;
    
   } 
}}

