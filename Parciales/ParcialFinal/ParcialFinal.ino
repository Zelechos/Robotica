#include<Servo.h>

Servo motor; 

void setup() {
  // put your setup code here, to run once:
  //    definimos el pin donde trabajar el servomotor
    motor.attach(9);
//    metodo para indicar a que posicion debe girar el servomotor
    motor.write(90);
}

void loop() {
  // put your main code here, to run repeatedly:
//  leftServo();
}

void stopServo(){
   motor.write(90);
   delay(3000);
}

//Rutina para girar a la Izquierda el ServoMotor
void leftServo(){
   motor.write(115);    
//   delay(1350);
//   motor.write(90);
}
