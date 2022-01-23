#include<Servo.h>
#define S0 22
#define S1 23
#define S2 24
#define S3 25
#define sensorSalida 26

Servo motor; 

void setup() {

//  Servomotor  
//  definimos el pin donde trabajar el servomotor
    motor.attach(9);
//    metodo para indicar a que posicion debe girar el servomotor
//    motor.write(90);
//    stopServo();
//    leftServo();
    
    

//  Sensor de Colores
    pinMode(S0, OUTPUT);
    pinMode(S1, OUTPUT);
    pinMode(S2, OUTPUT);
    pinMode(S3, OUTPUT);
    pinMode(sensorSalida, INPUT);
  
//    Configura la escala de Frecuencia en 20%
    digitalWrite(S0,HIGH);
    digitalWrite(S1,LOW);
  
    Serial.begin(9600);
}

// Sensor de Color
//
//    Arduino   TCS230 SENSOR COLOR
//    8 -> 26     OUT
//    7 -> 25     S3
//    6 -> 24     S2
//    5 -> 23     S1
//    4 -> 22     S0
//      5V        VCC
//      GND       GND
//
// By: http://elprofegarcia.com/
//

int Rojo_Frec = 0;
int Verde_Frec = 0;
int Azul_Frec = 0;

void loop() {
//  moveServo();
  sensorColor();

}

void moveServo(){
  leftServo();
  stopServo();
}


void stopServo(){
   motor.write(90);
   delay(3000);
}

//Rutina para girar a la Izquierda el ServoMotor
void leftServo(){
   motor.write(135);    
   delay(2000);
   motor.write(90);
}

void sensorColor(){

                            // Configura el filtor ROJO para tomar lectura
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
//  delay(100);
  Rojo_Frec= pulseIn(sensorSalida, LOW);
  Serial.print(" R= "); Serial.print(Rojo_Frec);
//  delay(100);
                            // Configura el filtor VERDE para tomar lectura
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
//  delay(100);
  Verde_Frec = pulseIn(sensorSalida, LOW);
  Serial.print(" V= "); Serial.print(Verde_Frec);
//  delay(100);
                           // Configura el filtor AZUL para tomar lectura
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
//  delay(100);
  Azul_Frec = pulseIn(sensorSalida, LOW);
  Serial.print(" A= "); Serial.print(Azul_Frec);
//  delay(100);

                  //Valores obtenidos en la calibracion del sensor, son propios de cada usuario 
                  
 if (Rojo_Frec < 140 && Verde_Frec > 80 && Azul_Frec > 80)  Serial.print(" . *** ROJO **");
 if (Rojo_Frec > 185 && Verde_Frec < 170 && Azul_Frec < 200)  Serial.print(" . *** VERDE **");
 if (Rojo_Frec > 130 && Verde_Frec > 200 && Azul_Frec >150)  Serial.print(" . *** NEGRO **");

//if (Rojo_Frec > 185 && Verde_Frec < 140 && Azul_Frec < 130)  Serial.print(" . *** VERDE **");
// if (Rojo_Frec > 80 && Verde_Frec > 100 && Azul_Frec < 80)  Serial.print(" . *** AZUL **");
// if (Rojo_Frec < 35 && Verde_Frec < 35 && Azul_Frec < 35)  Serial.print(" . *** BLANCO **");
 Serial.println("*");
// delay(100);
}
