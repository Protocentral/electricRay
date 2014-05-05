int sensorPin  = A0; //analog pin 0
int sensorPin1 = A1; //analog pin 1 
int sensorPin2 = A2; //analog pin 2

int pwm_a = 3;   //PWM control for motor outputs 1 and 2 is on digital pin 3
int pwm_b = 6;  //PWM control for motor outputs 3 and 4 is on digital pin 11
int dir_a1 = 4;
int dir_a2 = 2;
int dir_b1 = 5;
int dir_b2 = 7; 

void setup(){
  Serial.begin(9600);
  
  pinMode(pwm_a, OUTPUT);  //Set control pins to be outputs
  pinMode(pwm_b, OUTPUT);
  pinMode(dir_a1, OUTPUT);
  pinMode(dir_a2, OUTPUT);
  pinMode(dir_b1, OUTPUT);
  pinMode(dir_b2, OUTPUT);
  
}

void loop(){
  int val  = analogRead(sensorPin); //reading analog values for sensor1 
  int val1 = analogRead(sensorPin1);//reading analog values for sensor2
  int val2 = analogRead(sensorPin2);//reading analog values for sensor3
  static int temp1,temp2;
  Serial.println(val);
  //delay(500);
  Serial.println(val1);
  //delay(500);
  Serial.println(val2);
  //delay(500);
  
  if(val<100 && val1>100 && val2<100)
  {
    //delay(20);
    forward();
    delay(50);
    stopped();
  }
  if(val>100 && val1>100 && val2>100)
  {
    //delay(20);
    forward();
    delay(50);
    stopped();
  }
  if(val>100)
  {
    //delay(20);
    TurnRight();
    delay(10);
    stopped();
  }
  if(val>100 && val1>100)
  {
    //delay(20);
    TurnRight();
    delay(10);
    stopped();
  }
  if(val2>100)
  {
    //delay(20);
    TurnLeft();
    delay(10);
    stopped();
  }
  if(val1>100 && val2>100)
  {
  //delay(20);
  TurnLeft();
  delay(10);
  stopped();
}
/*if((val && val1 && val2) <100)
 {
   if(temp1 < temp2)
   {
     TurnRight();
     delay(5);
   }
   else
   {
     TurnLeft();
     delay(5);
   }
   
  }
  else
  {
   temp1 = val;
   temp2 = val2;
  }*/
}
/*
  void forward() //full speed forward
  { 
  digitalWrite(dir_a1, LOW);  //Set motor direction, 1 Low
  digitalWrite(dir_a2, HIGH);
  digitalWrite(dir_b1, LOW);  //Set motor direction, 2 Low
  digitalWrite(dir_b2, HIGH);
  analogWrite(pwm_a, 150);   //set motor 2 to run at 100% duty cycle (fast)
  analogWrite(pwm_b, 150);

  }
*/
  void forward() //turn right
  {
  digitalWrite(dir_a1,LOW );  //Reverse both motors direction, 1 high
  digitalWrite(dir_a2, HIGH);  
  digitalWrite(dir_b1, LOW);  //Reverse both motors direction, 2 high
  digitalWrite(dir_b2,HIGH );  
  analogWrite(pwm_a, 150);    //set motor A to run at 100% duty cycle (fast)
  analogWrite(pwm_b, 150);    //set motor B to run at 100% duty cycle (fast)
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
    digitalWrite(dir_a1, LOW);  //Set motor direction, 1 high
    digitalWrite(dir_a2, HIGH);
    digitalWrite(dir_b1, LOW);  //Set motor direction, 2 high
    digitalWrite(dir_b2, HIGH);
    analogWrite(pwm_a, 100);   //set motor 2 to run at 100% duty cycle (fast)
    analogWrite(pwm_b, 0);
  }

  void TurnLeft() //turn left
  {
    digitalWrite(dir_a1, LOW);  //Set motor direction, 1 low, 2 high
    digitalWrite(dir_a2,HIGH );
    digitalWrite(dir_b1,LOW );  //Set motor direction, 3 high, 4 low
    digitalWrite(dir_b2,HIGH );
    analogWrite(pwm_a, 0);   //set motor 1 to run at 100% duty cycle (fast)
    analogWrite(pwm_b, 100);
  }

