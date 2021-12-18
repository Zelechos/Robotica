//Librerias
#include<Servo.h>

Servo motor; 
byte number[10][8] = {
    {0, 0, 0, 0, 0, 0, 1, 1}, // 0
    {1, 0, 0, 1, 1, 1, 1, 1}, // 1
    {0, 0, 1, 0, 0, 1, 0, 1}, // 2
    {0, 0, 0, 0, 1, 1, 0, 1}, // 3
    {1, 0, 0, 1, 1, 0, 0, 1}, // 4 
    {0, 1, 0, 0, 1, 0, 0, 1}, // 5
    {0, 1, 0, 0, 0, 0, 0, 1}, // 6
    {0, 0, 0, 1, 1, 1, 1, 1}, // 7
    {0, 0, 0, 0, 0, 0, 0, 1}, // 8
    {0, 0, 0, 0, 1, 0, 0, 1} // 9
};

int count = 0;
String acceso;

void setup(){
    Serial.begin(9600);
    Serial1.begin(38400);//probamos en base la configuracion de bluethut

//    definimos el pin donde trabajar el servomotor
    motor.attach(9);
//    metodo para indicar a que posicion debe girar el servomotor
    motor.write(90);

    // manejo de pines del siete segmentos   
    for (byte i = 2; i <= 8; i++){
        pinMode(i, OUTPUT);
    }
}

void loop(){
    //  obtenemos la distancia del ultrasonico
    long distance = 0.01723 * readUltrasonicDistance(12, 13);
    
    if(distance < 30){

      executionSevenSegments();
      enviarMatricula();
      excutionServo();
      
//      Serial.print("Distancia ");
//      Serial.print(distance);
//      Serial.println(" cm");
    }


   if(Serial1.available() > 0){
      acceso = Serial1.read();//LA APLICACION NOS TIENE QUE MANDAR ESTE VALOR
      if(acceso == "88"){
        excutionServo();
      }   
   }
}

void enviarMatricula(){
    int numeroAleatorio = random(1000,100000);
      if(numeroAleatorio <= 0){
         numeroAleatorio = numeroAleatorio * -1;
      }else{
         String ci = String(numeroAleatorio);
         Serial1.println(ci);
      }
}

//Ejecucion del servomotor
void excutionServo(){
    rightServo();
    stopServo();
    leftServo();
}

//Rutina para detener el movimiento de el ServoMotor
void stopServo(){
   motor.write(90);
   delay(3000);
}

//Rutina para girar a la Derecha el ServoMotor
void rightServo(){
   motor.write(68);    
   delay(1700);
   motor.write(90);
}

//Rutina para girar a la Izquierda el ServoMotor
void leftServo(){
   motor.write(115);    
   delay(1450);
   motor.write(90);
}

//ejecucion del siete segmentos 
void executionSevenSegments(){
  count++;
  //  mostramos los numeros en el siete segmentos
  sevenSegments(count);
  if(count == 9){
    count = 0;
  }
}

//rutina para el funcionamiento de el UltraSonico
long readUltrasonicDistance(int triggerPin, int echoPin){
    
    // iniciamos el trigger
    pinMode(triggerPin, OUTPUT);

    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);


    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);


    pinMode(echoPin, INPUT);

    return pulseIn(echoPin, HIGH);
}

//rutina para el manejo de los numeros del Siete Segmentos
void sevenSegments(byte num){
  for( byte i= 0; i <= 7 ; i++){
    digitalWrite(i+2 , number[num][i]);  
  }
}
