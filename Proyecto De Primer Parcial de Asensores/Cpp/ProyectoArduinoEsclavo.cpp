//============= ESCLAVO =============
#include <LiquidCrystal.h>

// Conectamos los pines de la Pantalla LCD a el Arduino
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup() {
    Serial.begin(9600);

  // Inicializamos las pantalla LCD
    lcd.begin(16, 2);//(Columnas, Filas)

    initial_message();
}

void loop() {
    // lcd.clear();
  if (pisonumber > 0 && pisonumber <= 33){
  }else{
      Serial.println("piso NO EXISTE!!!!");
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

void alert_message(int piso, int piso_next){
    lcd.setCursor(1, 0);
    lcd.print("Hacia Piso ");
  // Posiciones en los que escribimos en Mensaje
    lcd.setCursor(4, 1);
  // Pintamos un mensaje en el LCD.
    lcd.print("Siguiente Piso ");
}

