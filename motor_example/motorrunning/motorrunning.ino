
int pwm_a = 3;   //PWM control for motor outputs 1 and 2 is on digital pin 3
int pwm_b = 6;  //PWM control for motor outputs 3 and 4 is on digital pin 11
int dir_a1 = 4;
int dir_a2 = 2;
int dir_b1 = 5;
int dir_b2 = 7; 

void setup(){
  Serial.begin(9600);
  
  pinMode(pwm_a,  OUTPUT);  //Set control pins to be outputs
  pinMode(pwm_b,  OUTPUT);
  pinMode(dir_a1, OUTPUT);  //set motor direction output
  pinMode(dir_a2, OUTPUT);
  pinMode(dir_b1, OUTPUT);
  pinMode(dir_b2, OUTPUT);
}

void loop(){
 
    forward();
    delay(2000);
    stopped();
    delay(2000);
    backward();
    delay(2000);
    stopped();
    delay(2000);

}

 void forward() //full speed forward
{ 
  digitalWrite(dir_a1, HIGH);  //Reverse both motors direction, 1 high
  digitalWrite(dir_a2, LOW);  
  digitalWrite(dir_b1, HIGH);  //Reverse both motors direction, 2 high
  digitalWrite(dir_b2, LOW);  
  analogWrite(pwm_a, 255);    //set motor A to run at 100% duty cycle (fast)
  analogWrite(pwm_b, 255);    //set motor B to run at 100% duty cycle (fast)
}

void backward() //turn right
{
  digitalWrite(dir_a1, LOW);  //Set motor direction, 1 Low
  digitalWrite(dir_a2, HIGH);
  digitalWrite(dir_b1, LOW);  //Set motor direction, 2 Low
  digitalWrite(dir_b2, HIGH);
  analogWrite(pwm_a, 255);   //set motor 2 to run at 100% duty cycle (fast)
  analogWrite(pwm_b, 255);
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
 
