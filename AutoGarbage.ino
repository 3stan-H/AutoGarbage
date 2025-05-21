#include <Servo.h> // servo library
Servo s1;
int trigPin = 10;
int echoPin = 9;
long duration;
int distanceCm, distanceInch;
void setup()
{

Serial.begin(9600); //initializing console
pinMode(trigPin, OUTPUT); //initializing pin modes
pinMode(echoPin, INPUT);
s1.attach(3);   // pinmode for Servo Motor



}
void loop() 
{ 
digitalWrite(trigPin, LOW); //constantly measures the ultrasonic sensors distance from the object
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
distanceInch = duration*0.0133/2;
Serial.println("Distance: ");
Serial.println(distanceCm);
delay(50);

if(distanceCm < 20)
{ //once conditon is met the motor is set to the open position

 s1.write(140);
 delay(1500);

}

else
{ //default conditon (closed position)
   s1.write(45);
    delay(10);

 
}

}
