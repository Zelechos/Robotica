//============= ESCLAVO =============
#include <Wire.h> // Libreria para la Comunicacion I2C (maestro-esclavo)
#include <LiquidCrystal.h>

// Conectamos los pines de la Pantalla LCD a el Arduino
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup() {
    Serial.begin(9600);
  // Inicializamos las pantalla LCD
    lcd.begin(16, 2);//(Columnas, Filas)

    initial_message();
    // aqui se identifica con el numero del esclavo
    Wire.begin(1);
// Es ejecuta solo cuando hay un dato de entrada
    Wire.onReceive(eventReceive);
}

void loop() {
  delay(200);
}

void eventReceive(int howMany){
  int value;
  if (Wire.available()>0){
      char data = Wire.read();
      if (data != '0'){
        lcd.clear();
        alert_message(data);
      }else{
        lcd.clear();
        error_message();
      }
  }
}

void initial_message(){
    lcd.setCursor(1, 0);
    lcd.print("(Welcome to)=>");
  // Posiciones en los que escribimos en Mensaje
    lcd.setCursor(4, 1);
  // Pintamos un mensaje en el LCD.
    lcd.print("{Google}");
}

void alert_message(char piso){
    lcd.setCursor(0, 0);
    lcd.print("Piso Elegido:");
  // Posiciones en los que escribimos en Mensaje
    lcd.setCursor(8, 1);
  // Pintamos un mensaje en el LCD.
    lcd.print(piso);
}

void error_message(){
    lcd.setCursor(0, 0);
    lcd.print("Piso NO Existe!");
}

