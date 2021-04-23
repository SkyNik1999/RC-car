
#include <AFMotor.h>

//initial motors pin
AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ); 
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);
int light_FR=  0;    //LED Front Right   pin A0 for Arduino Uno
int light_FL=  1;    //LED Front Left    pin A1 for Arduino Uno
int light_BR=  2;    //LED Back Right    pin A2 for Arduino Uno
int light_BL=  3;    //LED Back Left     pin A3 for Arduino Uno
char command; 

void setup() 
{  
  pinMode(light_FR,OUTPUT);
  pinMode(light_FL,OUTPUT);
  pinMode(light_BR,OUTPUT);
  pinMode(light_BL,OUTPUT);     
  Serial.begin(9600);  //Set the baud rate to your Bluetooth module.
}

void loop()
{
  if(Serial.available() > 0)
  { 
    command = Serial.read(); 
    Stop(); //initialize with motors stoped
    //Change pin mode only if new command is different from previous.   
    //Serial.println(command);
    
   switch (command) 
   {
case 'F':forward();break;
case 'B':back();break;
case 'L':left();break;
case 'R':right();break;
case 'W':lightFront();break;
case 'w':lightFront();break;
case 'U':lightBack() ;break;
case 'u':lightBack();break;


}
  } 
}

void lightFront()
{
  if(lightFront== true)
  {
  analogWrite(light_FR, 255); 
  analogWrite(light_FL, 255);
  }
  else
  {
  analogWrite(light_FR, 0); 
  analogWrite(light_FL, 0);
  }
}
void lightBack()
{
  if(lightBack== true)
  {
  analogWrite(light_FR, 255); 
  analogWrite(light_FL, 255);
  }
  else
  {
  analogWrite(light_FR, 0); 
  analogWrite(light_FL, 0);
  }
}
void forward()
{
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
  motor3.setSpeed(255);//Define maximum velocity
  motor3.run(FORWARD); //rotate the motor clockwise
  motor4.setSpeed(255);//Define maximum velocity
  motor4.run(FORWARD); //rotate the motor clockwise
  
}

void back()
{
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(255); //Define maximum velocity
  motor3.run(BACKWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(255); //Define maximum velocity
  motor4.run(BACKWARD); //rotate the motor anti-clockwise
}

void left()
{
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(255); //Define maximum velocity
  motor3.run(FORWARD);  //rotate the motor clockwise
  motor4.setSpeed(255); //Define maximum velocity
  motor4.run(FORWARD);  //rotate the motor clockwise
}

void right()
{
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
  motor3.setSpeed(255); //Define maximum velocity
  motor3.run(BACKWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(255); //Define maximum velocity
  motor4.run(BACKWARD); //rotate the motor anti-clockwise
} 

void Stop()
{
  motor1.setSpeed(0); //Define minimum velocity
  motor1.run(RELEASE); //stop the motor when release the button
  motor2.setSpeed(0); //Define minimum velocity
  motor2.run(RELEASE); //rotate the motor clockwise
  motor3.setSpeed(0); //Define minimum velocity
  motor3.run(RELEASE); //stop the motor when release the button
  motor4.setSpeed(0); //Define minimum velocity
  motor4.run(RELEASE); //stop the motor when release the button
}
