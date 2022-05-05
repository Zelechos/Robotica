#include<Servo.h>
#define S0 22
#define S1 23
#define S2 24
#define S3 25
#define sensorSalida 26

Servo motor; 
String acceso;
void setup() {
  Serial1.begin(38400);//probamos en base la configuracion de bluethut
//  Servomotor  
//  definimos el pin donde trabajar el servomotor
    motor.attach(9);
//    metodo para indicar a que posicion debe girar el servomotor
//    motor.write(90);

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
//      26       OUT
//      25        S3
//      24        S2
//      23        S1
//      22        S0
//      5V        VCC
//      GND       GND
//
// By: http://elprofegarcia.com/
//

int Rojo_Frec = 0;
int Verde_Frec = 0;
int Azul_Frec = 0;

void loop() {
  int valueColor;
//  obtenemos la distancia del ultrasonico
  long distance = 0.01723 * readUltrasonicDistance(28, 29);
  
   valueColor = sensorColor();
   if(valueColor == 1){
      motor.write(90);
      Serial.println(valueColor);
      Serial.println("Retire la caja con Covid");
      delay(20000);
   }

//   Distancia de Sensor Ultrasonico
  if(distance < 10){
    Serial.println("Producto Aceptado!!!!");
    sendProducto();
  }else{
    Serial.println("Esperando Productor . . .");
  }


   if(Serial1.available() > 0){
      acceso = Serial1.read();//LA APLICACION NOS TIENE QUE MANDAR ESTE VALOR
      if(acceso == "88"){
        moveServo();
      }   
   }

//  Mover Servormotor
   moveServo();
}

void sendProducto(){
     Serial1.println("X");
}

void sendColor(String color){
  Serial1.println(color);
}

void moveServo(){
  leftServo();
  stopServo();
}

//Rutina para detener el ServoMotor
void stopServo(){
   motor.write(90);
   delay(4000);
}

//Rutina para girar a la Izquierda el ServoMotor
void leftServo(){
   motor.write(140);    
   delay(2200);
   motor.write(90);
}

//Rutina para el funcionamiento de el UltraSonico
long readUltrasonicDistance(int triggerPin, int echoPin){
    
    // iniciamos el trigger
    pinMode(triggerPin, OUTPUT);

    digitalWrite(triggerPin, LOW);
    delayMicroseconds(4);


    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);


    pinMode(echoPin, INPUT);

    return pulseIn(echoPin, HIGH);
}


int sensorColor(){

// Configura el filtor ROJO para tomar lectura
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);


  Rojo_Frec= pulseIn(sensorSalida, LOW);
  Serial.print(" R= "); Serial.print(Rojo_Frec);

                            // Configura el filtor VERDE para tomar lectura
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);


  Verde_Frec = pulseIn(sensorSalida, LOW);
  Serial.print(" V= "); Serial.print(Verde_Frec);

                           // Configura el filtor AZUL para tomar lectura
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);

  Azul_Frec = pulseIn(sensorSalida, LOW);
  Serial.print(" A= "); Serial.print(Azul_Frec);


//Valores obtenidos en la calibracion del sensor, son propios de cada usuario 
 int value = 0;
 if (Rojo_Frec < 200 && Verde_Frec > 80 && Azul_Frec > 80){
  Serial.print(" . *** ROJO **");
  sendColor("ROJO");
  return 1;
 }
 if (Rojo_Frec > 300 && Verde_Frec < 300 && Azul_Frec < 330){
  Serial.print(" . *** VERDE **");
  sendColor("VERDE");
  return 2;
 }
 if (Rojo_Frec > 130 && Verde_Frec > 200 && Azul_Frec >150){
  Serial.print(" . *** NEGRO **");
  sendColor("NEGRO");
  return 0;
 }

//if (Rojo_Frec > 185 && Verde_Frec < 140 && Azul_Frec < 130)  Serial.print(" . *** VERDE **");
// if (Rojo_Frec > 80 && Verde_Frec > 100 && Azul_Frec < 80)  Serial.print(" . *** AZUL **");
// if (Rojo_Frec < 35 && Verde_Frec < 35 && Azul_Frec < 35)  Serial.print(" . *** BLANCO **");
 Serial.println("*");
  return -1;
}
