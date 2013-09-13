
int pwm_a = 3;   //PWM control for motor outputs 1 and 2 is on digital pin 3
int pwm_b = 6;  //PWM control for motor outputs 3 and 4 is on digital pin 11
int dir_a1 = 4;
int dir_a2 = 2;
int dir_b1 = 5;
int dir_b2 = 7; 

#define trigPin A5
#define echoPin A4

void setup(){
  Serial.begin(9600);
  
  pinMode(pwm_a,  OUTPUT);  //Set control pins to be outputs
  pinMode(pwm_b,  OUTPUT);
  pinMode(dir_a1, OUTPUT);  //set motor direction output
  pinMode(dir_a2, OUTPUT);
  pinMode(dir_b1, OUTPUT);
  pinMode(dir_b2, OUTPUT);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop(){
  
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  //  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1; //calculate distance in cm

  if (distance <= 10){
    stopped();
    delay(100);
    backward();
    delay(1000);
    TurnRight();
    delay(500);
    stopped();
    delay(100);
  }
  else {
       forward();
       delay(100);    
  }

}

 void forward() //full speed forward
{ 
  digitalWrite(dir_a1, HIGH);  //Reverse both motors direction, 1 high
  digitalWrite(dir_a2, LOW);  
  digitalWrite(dir_b1, HIGH);  //Reverse both motors direction, 2 high
  digitalWrite(dir_b2, LOW);  
  analogWrite(pwm_a, 150);    //set motor A to run at 100% duty cycle (fast)
  analogWrite(pwm_b, 150);    //set motor B to run at 100% duty cycle (fast)
}

void backward() //turn right
{
  digitalWrite(dir_a1, LOW);  //Set motor direction, 1 Low
  digitalWrite(dir_a2, HIGH);
  digitalWrite(dir_b1, LOW);  //Set motor direction, 2 Low
  digitalWrite(dir_b2, HIGH);
  analogWrite(pwm_a, 150);   //set motor 2 to run at 100% duty cycle (fast)
  analogWrite(pwm_b, 150);
}
 void stopped() //stop the motor
{
  digitalWrite(dir_a1, LOW);  //Set motor direction, 1 low
  digitalWrite(dir_a2, LOW);
  digitalWrite(dir_b1, LOW);  //Set motor direction, 2 low
  digitalWrite(dir_b2, LOW);
  analogWrite(pwm_a, 0);   //set both motors to stop(0)
  analogWrite(pwm_b, 0);
}
 
 void TurnRight() //turn right
{
  digitalWrite(dir_a1, HIGH);  //Set motor direction, 1 high
  digitalWrite(dir_a2, LOW);
  digitalWrite(dir_b1, HIGH);  //Set motor direction, 2 high
  digitalWrite(dir_b2, LOW);
  analogWrite(pwm_a, 100);   //set motor 2 to run at 100% duty cycle (fast)
  analogWrite(pwm_b, 0);
}

void TurnLeft() //turn left
{
  digitalWrite(dir_a1, HIGH);  //Set motor direction, 1 low, 2 high
  digitalWrite(dir_a2, LOW);
  digitalWrite(dir_b1, HIGH);  //Set motor direction, 3 high, 4 low
  digitalWrite(dir_b2, LOW);
  analogWrite(pwm_a, 0);   //set motor 1 to run at 100% duty cycle (fast)
  analogWrite(pwm_b, 100);
}
