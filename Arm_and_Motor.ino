/*************************************************** 
  This is an example for our Adafruit 16-channel PWM & Servo driver
  Servo test

 ****************************************************/

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <SoftwareSerial.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  150 
#define SERVOMAX  600 

SoftwareSerial robot (10,11); // RX,TX
uint16_t bluetooth;

int servo_position_Gripper = 0;
int degree_Gripper=0;

int servo_position_Base = 0;
int degree_Base=0;

int servo_position_Shoulder = 0;
int degree_Shoulder=0;

int servo_position_Elbow = 0;
int degree_Elbow=0;


int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;

#define servoGripper   0
#define servoBase      1
#define servoShoulder  2
#define servoElbow     3




void setup() {
  
  // Pino motores
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);


  
  Serial.begin(9600);
  robot.begin(9600);

  pwm.begin();
  
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  
  pwm.setPWM(servoGripper, 0, 0); 
  pwm.setPWM(servoBase, 0, 0); 
  pwm.setPWM(servoShoulder, 0, 0); 
  pwm.setPWM(servoElbow, 0, 0);   
  
  delay(10);



}


void loop() {

if (robot.available() > 0) {
    bluetooth = (char)robot.read();
    
    switch (bluetooth){
     case 'C':
        controlServo_Shoulder(servoShoulder,'P');
      break;
      
      case 'D':
        controlServo_Shoulder(servoShoulder,'L');
      break;
      
      case 'E':
        controlServo_Elbow(servoElbow,'P');
      break;

      case 'F':
         controlServo_Elbow(servoElbow,'L');
      break;
      
      case 'G':
          controlServo_Gripper(servoGripper,'P');
      break;
          
      case 'H':
          controlServo_Gripper(servoGripper,'L');
      break;

      case 'B':
        controlServo_Base(servoBase,'P');
      break;

      case 'A':
        controlServo_Base(servoBase,'L');
      break;
                   
      case 'R':
      motor_A_frente();
      motor_B_frente();  
      break;

      case 'O':
      motor_A_atras();
      motor_B_frente();
      break;

      case 'P':
      motor_A_frente();
      motor_B_atras();
      break;

      case 'Q':
      motor_A_atras();
      motor_B_atras();
      break;
      case 'S':
      motor_B_parar();
      motor_A_parar();
      break;   
    }
  }

  
}

  void controlServo_Base( int numberServo, char incremento){
      
      if( incremento == 'P'){
          
          if(servo_position_Base<180){
            servo_position_Base ++;
            degree_Base = map (servo_position_Base,0,180,SERVOMIN,SERVOMAX);
            pwm.setPWM(numberServo, 0, degree_Base); 
            delay(5); 
          }
    }  
    else if (incremento == 'L'){
        
        if(servo_position_Base>0){
           servo_position_Base--;
           degree_Base = map (servo_position_Base,0,180,SERVOMIN,SERVOMAX);
           pwm.setPWM(numberServo, 0, degree_Base);  
           delay(5);
       }
    }
  }




 void controlServo_Gripper( int numberServo, char incremento){
      
      if( incremento == 'P'){
          
          if(servo_position_Gripper<180){
            servo_position_Gripper ++;
            degree_Gripper = map (servo_position_Gripper,0,180,SERVOMIN,SERVOMAX);
            pwm.setPWM(numberServo, 0, degree_Gripper); 
            delay(5); 
          }
    }  
    else if (incremento == 'L'){
        
        if(servo_position_Gripper>0){
           servo_position_Gripper--;
           degree_Gripper = map (servo_position_Gripper,0,180,SERVOMIN,SERVOMAX);
           pwm.setPWM(numberServo, 0, degree_Gripper);  
           delay(5);
       }
    }
  }



 void controlServo_Shoulder( int numberServo, char incremento){
      
      if( incremento == 'P'){
          
          if(servo_position_Shoulder<180){
            servo_position_Shoulder ++;
            degree_Shoulder = map (servo_position_Shoulder,0,180,SERVOMIN,SERVOMAX);
            pwm.setPWM(numberServo, 0, degree_Shoulder); 
            delay(5); 
          }
    }  
    else if (incremento == 'L'){
        
        if(servo_position_Shoulder>0){
           servo_position_Shoulder--;
           degree_Shoulder = map (servo_position_Shoulder,0,180,SERVOMIN,SERVOMAX);
           pwm.setPWM(numberServo, 0, degree_Shoulder);  
           delay(5);
       }
    }
  }



void controlServo_Elbow( int numberServo, char incremento){
      
      if( incremento == 'P'){
          
          if(servo_position_Elbow<180){
            servo_position_Elbow ++;
            degree_Elbow = map (servo_position_Elbow,0,180,SERVOMIN,SERVOMAX);
            pwm.setPWM(numberServo, 0, degree_Elbow); 
            delay(5); 
          }
    }  
    else if (incremento == 'L'){
        
        if(servo_position_Elbow>0){
           servo_position_Elbow--;
           degree_Elbow = map (servo_position_Elbow,0,180,SERVOMIN,SERVOMAX);
           pwm.setPWM(numberServo, 0, degree_Elbow);  
           delay(5);
       }
    }
  }
  

  //      *** MOTOR A ***
void motor_A_frente(){

 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, LOW); 
}

void motor_A_parar(){

 digitalWrite(IN1, LOW);
 digitalWrite(IN2, LOW);
  }

void motor_A_atras(){


 digitalWrite(IN1, LOW);
 digitalWrite(IN2, HIGH);
}

//    ***   MOTOR B ***

void motor_B_frente(){  

 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, LOW);
}
void motor_B_parar(){
  //Parar o motor B
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, LOW); 
}
void motor_B_atras(){

 digitalWrite(IN3, LOW);
 digitalWrite(IN4, HIGH);
}
