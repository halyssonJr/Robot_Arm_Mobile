//#include<SoftwareSerial.h>

// Variáveis
int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;
int bluetooth; 
// end Variáveis

//SoftwareSerial carrinho(10,11) // (TX, RX) 


// SETUP
void setup()
{
 // Pino motores
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);
// Comunicação Serial
 Serial.begin(9600);

}
// end SETUP



// LOOP 
void loop()
{

     if (Serial.available() > 0) {
    
    bluetooth = Serial.read();
   
    if (bluetooth == 'R'){
      motor_A_frente();
      motor_B_frente();  
    } 
    
    if (bluetooth == 'B'){
      motor_A_atras();
      motor_B_atras();
    }

    if (bluetooth == 'L'){
      motor_A_atras();
      motor_B_frente();
    }

    if (bluetooth == 'R'){
      motor_A_frente();
      motor_B_atras();
    }

    
    if (bluetooth == 'S'){
      motor_B_parar();
      motor_A_parar();
    }

  }

 
}
// end LOOP

//      *** MOTOR A ***
void motor_A_frente(){
//Gira o Motor A no sentido horario
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, LOW); 
}

void motor_A_parar(){
  //Parar o motor A
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, LOW);
  }

void motor_A_atras(){

//Gira o Motor A no sentido anti-horario
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, HIGH);
}

//    ***   MOTOR B ***

void motor_B_frente(){  
//Gira o Motor B no sentido horario
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, LOW);
}
void motor_B_parar(){
  //Parar o motor B
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, LOW); 
}
void motor_B_atras(){
//Gira o Motor B no sentido anti-horario
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, HIGH);
}
