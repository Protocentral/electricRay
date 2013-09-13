int sensorPin  = A2; //analog pin 0
int sensorPin1 = A0; //analog pin 1 
int sensorPin2 = A1; //analog pin 2

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
  
  pinMode(sensorPin, INPUT);
  pinMode(sensorPin1, INPUT);
  pinMode(sensorPin2, INPUT);
}

void loop(){
  int val  = analogRead(sensorPin); //reading analog values for sensor1 
  int val1 = analogRead(sensorPin1);//reading analog values for sensor2
  int val2 = analogRead(sensorPin2);//reading analog values for sensor3
  
  Serial.print(val);
  Serial.println("senleft");
  delay(500);
  Serial.print(val1);
  Serial.println("Centersens");
  delay(500);
  Serial.print(val2);
  Serial.println("senright");
  delay(500);
  
  
  if( val>800 && val1>800 && val2>800)
  {
    forward();
    delay(100);
    stopped();
    delay(50);
  }
  if(val>800)
  {
    TurnLeft();
    delay(100);
    stopped();
    delay(50);
  }
  if(val2>800)
  {
    TurnRight();
    delay(10);
    stopped();
    delay(10);
  }
 /* if(val2<800 && val1<800)
  {
    TurnRight();
    delay(80);
    stopped();
    delay(30);
  }
  if(val1<800 && val2<800){
  TurnLeft();
  delay(80);
  stopped();
  delay(30);
  }*/
  if(val<800 && val1<800 && val2<800){
    stopped();
    delay(100);
  }
}


 void forward() //full speed forward
{ 
  digitalWrite(dir_a1, HIGH);  //Reverse both motors direction, 1 high
  digitalWrite(dir_a2, LOW);  
  digitalWrite(dir_b1, HIGH);  //Reverse both motors direction, 2 high
  digitalWrite(dir_b2, LOW);  
  analogWrite(pwm_a, 100);    //set motor A to run at 100% duty cycle (fast)
  analogWrite(pwm_b, 100);    //set motor B to run at 100% duty cycle (fast)
}

void TurnRight() //turn right
{
  digitalWrite(dir_a1, HIGH);  //Set motor direction, 1 high
  digitalWrite(dir_a2, LOW);
  digitalWrite(dir_b1, HIGH);  //Set motor direction, 2 high
  digitalWrite(dir_b2, LOW);
  analogWrite(pwm_a, 0);   //set motor 2 to run at 100% duty cycle (fast)
  analogWrite(pwm_b, 90);
}

void TurnLeft() //turn left
{
  digitalWrite(dir_a1, HIGH);  //Set motor direction, 1 low, 2 high
  digitalWrite(dir_a2, LOW);
  digitalWrite(dir_b1, HIGH);  //Set motor direction, 3 high, 4 low
  digitalWrite(dir_b2, LOW);
  analogWrite(pwm_a, 90);   //set motor 1 to run at 100% duty cycle (fast)
  analogWrite(pwm_b, 0);
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
 
