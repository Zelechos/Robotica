//PRACTICA 5 : TUMIRI HUANCA ALEX
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
char voidState = '0';
byte counter = 0;

//================= VARIABLES ====================

void setup(){
//    Serial.begin(9600);
    Serial1.begin(38400);//probamos en base la configuracion de bluethut
    
    for (byte i = 2; i <= 8; i++){
        pinMode(i, OUTPUT);
    }
}


void loop() {
  // put your main code here, to run repeatedly:
  if(Serial1.available() > 0){
    voidState = Serial1.read();//LA APLICACION NOS TIENE QUE MANDAR ESTE VALOR
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

  //DENTENTE
  if(voidState == '0'){
    counter = 0;
    sevenSegments(counter);
  }
  
  sevenSegments(counter);
}

//metodo para el manejo de los numeros
void sevenSegments(byte num){
  for( byte i= 0; i <= 7 ; i++){
    digitalWrite(i+2 , number[num][i]);  
  }
}
