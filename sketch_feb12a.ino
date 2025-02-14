#include <Servo.h>          //Include the servo motor library.
#include <NewPing.h>        //Ultrasonic sensor function library

int echo_pin = 11;           //Define pin 11 as echo for the ultrasonic sensor
int trig_pin = 12;           //Define pin 12 as trig for the ultrasonic sensor

float timing = 0.0;
float distance = 0.0;
float distanceright= 0.0;
float distanceleft=0.0;     //Define the above variables as float 

int rightmotor_1 = 3;
int rightmotor_2 = 4;
int leftmotor_1 = 5;
int leftmotor_2 = 6;       //The variables for the control of the two motors are matched to the pins 

Servo myservo;             //Declaration of the servomotor with the name my servo

void setup() {
  // put your setup code here, to run once:
  
  pinMode(echo_pin, INPUT);       
  pinMode(trig_pin, OUTPUT);
  
  pinMode(rightmotor_1, OUTPUT);
  pinMode(rightmotor_2, OUTPUT);
  pinMode(leftmotor_1, OUTPUT);
  pinMode(leftmotor_2, OUTPUT);             //Define the input and output variables 

  digitalWrite(trig_pin, LOW);              //The ultrasonic sensor doesn t emit

  myservo.attach(9);                        //Set the control pin of Arduino, which connects to the signal pin of the servo motor
  myservo.write(90);                        //Rotate the angle of the motor to 90 degrees
  delay(500); 
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(rightmotor_1, HIGH);
  digitalWrite(rightmotor_2, LOW);
  
  digitalWrite(leftmotor_1, HIGH);
  digitalWrite(leftmotor_2, LOW);         //Both motors are put into forward motion, so the robot moves forward

    
  
  digitalWrite(trig_pin, LOW);
  delay(2);

  digitalWrite(trig_pin, HIGH);           //The emission starts for 10 ms
  delay(10);
  digitalWrite(trig_pin, LOW);            //The emission stops

  timing = pulseIn(echo_pin, HIGH);       //Calculates the time needed to detect the echo of the emission
  distance = (timing * 0.034) / 2;        //Calculates the distance

    
  
  if (distance <=40) {                   // Checks if the object is closer than 40 cm
    digitalWrite(rightmotor_1, LOW);
    digitalWrite(rightmotor_2, LOW);
    
    digitalWrite(leftmotor_1, LOW);
    digitalWrite(leftmotor_2, LOW);      //The car stops 

    myservo.write(15);                   //Rotates the angle of the servo to 15 degrees and then calculates the distance in this angle
    delay(2000);                         // Delays the calculation of the time, so that the servo has enough time to take the specific angle
    
    digitalWrite(trig_pin, LOW);         //Then calculates the distance in this angle (15 degrees)
    delay(2);

    digitalWrite(trig_pin, HIGH);
    delay(10);
    digitalWrite(trig_pin, LOW);

  timing = pulseIn(echo_pin, HIGH);
  distanceright = (timing * 0.034) / 2;
  
  delay(500);                           
myservo.write(165);                     //Rotates the angle of the servo to 165 degrees and then calculates the distance in this angle
delay(2000);                            // Delays the emission of the sound wave, so that the servo has enough time to take the specific angle
   
    digitalWrite(trig_pin, LOW);         //Then calculates the distance in this angle (165 degrees)
    delay(2);

    digitalWrite(trig_pin, HIGH);
    delay(10);
    digitalWrite(trig_pin, LOW);

  timing = pulseIn(echo_pin, HIGH);
  distanceleft = (timing * 0.034) / 2;   
  
  delay(500);
  
  if (distanceright >=distanceleft) {     //Compares the two distances and if the distance right is greater than the distance left
  digitalWrite(rightmotor_1, HIGH);
  digitalWrite(rightmotor_2, LOW);
  
  digitalWrite(leftmotor_1, LOW);
  digitalWrite(leftmotor_2, HIGH);        //The robot car turns right 
  delay(100);
  } 
  else {
    digitalWrite(rightmotor_1, LOW);
    digitalWrite(rightmotor_2, HIGH);
  
    digitalWrite(leftmotor_1, HIGH);
    digitalWrite(leftmotor_2, LOW);       //The robot car turns left 
    delay(100);
  }
myservo.write(90);
delay(300);
  }


}
