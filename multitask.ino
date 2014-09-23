#include <Servo.h> 

int top=A1;
int left=A2;
int bottom=A3;
int right=A4;
int enlight=12;
int media;
int v_top=0;
int v_left=0;
int v_bottom=0;
int v_right=0;
int mode;
int sensibility=400;

/*Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
 
int pos = 0;    // variable to store the servo position 
int dir=0; //direzione del movimento del servo
*/
int motor1Pin1 = 9;    // pin 2 on L293D    sinistra
int motor1Pin2 = 8.;    // pin 7 on L293D   sinistra

int motor2Pin1 =7 ;    // pin 2 on L293D   destra
int motor2Pin2 =6 ;    // pin 7 on L293D   destra


void setup() {

  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
 // myservo.attach(5);  // attaches the servo on pin 9 to the servo object 

  pinMode(enlight, OUTPUT);
  digitalWrite(enlight, HIGH);
  
}

void loop() {

v_top = analogRead(top);
v_left  = analogRead(left);
v_bottom  = analogRead(bottom);
v_right  = analogRead(right);
/*
if (pos==60) dir=1;
if (pos==0) dir=0;
if (dir==0) pos++;
else pos--;
myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);    
 */   
media=(v_top+v_left+v_bottom+v_right)/4;
if (media>sensibility) mode=1;
else mode=0;

if (mode==0) {
    digitalWrite(motor1Pin1, LOW);   // set pin 2 on L293D low
    digitalWrite(motor1Pin2, HIGH);  // set pin 7 on L293D high
    digitalWrite(motor2Pin1, LOW);   // set pin 2 on L293D low
    digitalWrite(motor2Pin2, HIGH);  // set pin 7 on L293D high
 
}
else {
  
      
    if(/*random(0,2)*/0==0) {
    digitalWrite(motor1Pin1, LOW);   // set pin 2 on L293D low
    digitalWrite(motor1Pin2, HIGH);  // set pin 7 on L293D high
    digitalWrite(motor2Pin1, HIGH);   // set pin 2 on L293D low
    digitalWrite(motor2Pin2, LOW);  // set pin 7 on L293D high
    }
    else{
    
    digitalWrite(motor2Pin1, LOW);   // set pin 2 on L293D low
    digitalWrite(motor2Pin2, HIGH);  // set pin 7 on L293D high
    digitalWrite(motor1Pin1, HIGH);   // set pin 2 on L293D low
    digitalWrite(motor1Pin2, LOW);  // set pin 7 on L293D high
    
    }
    
    
    delay(400);
}



}
