#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
    Serial.begin(9600);
  // set up the LCD's number of columns and rows:
    // lcd.begin(16, 2);
  // Print a message to the LCD.
    // lcd.print("hello, world!");
}

void loop() {
    // lcd.setCursor(0, 1);
  // print the number of seconds since reset:
    // lcd.print(millis() / 1000);
    int lectura = analogRead(A0);
    Serial.println(lectura);
}
