#include <Wire.h>

//CONTINUAR MINUTO 59
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
char voidState;

//================= VARIABLES ====================

void setup()
{
  for(byte i = 4; i<=10; i++){
    pinMode(i,OUTPUT);
  }
  
  Serial.begin(9600);

  
  //stopCounter();
  //ascendingNumber();
  //descendingNumber(); 
  
}

byte counter = 0;
void loop() {
  // put your main code here, to run repeatedly:
  // ascendingNumber();

  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    voidState = Serial.read();//LA APLICACION NOS TIENE QUE MANDAR ESTE VALOR
  }

  //ASCENDENTE 
  if(voidState == '2'){
      sevenSegments(counter);
      counter++;
      delay(900);
      if(counter > 9){
        counter = 0;
      }    
  }
  
  //DESCENDENTE 
  if (voidState == '1'){
    if(counter == 0 ){
      sevenSegments(counter);
      delay(900);
      counter = 9;
    }    
    sevenSegments(counter);
    counter--;
    delay(900);
  }


  if(voidState == '0'){
    counter = 0;
    sevenSegments(counter);
  }
  sevenSegments(counter);
}

//metodo para el manejo de los numeros
void sevenSegments(byte num){
  for( byte i= 0; i <= 7 ; i++){
    //digitalWrite(i+2 , number[num][i]);  
    digitalWrite(i+4 , number[num][i]);  
  }
}


//metodo que el numero ascienda
byte ascendingNumber(byte number){
  boolean state;
  sevenSegments(number);
  delay(900);
  if(number == 9){
    number = -1;
  } 

  if(voidState == '0'){
    state = true;
    Serial.println("state as true");
  }
  
  if (voidState == '1'){
    state = false;
    Serial.println("state as false");
  }   
  
  if(state == false){
    return number;
  }

  if(state){
    return ascendingNumber(number+1);
  }
}


//metodo que el numero descienda
byte descendingNumber(byte number){
  sevenSegments(number);
  delay(900);
  if(number == 0){
    number = 9;
  }
  return number;
}

void stopCounter(){
    sevenSegments(0);
}


