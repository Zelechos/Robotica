//============= MAESTRO =============
#include <Wire.h> // Libreria para la Comunicacion I2C (maestro-esclavo)
#include <Keypad.h>//Libreria para manejar el Teclado Matricial

const byte ROWS = 4; //cuatro filas
const byte COLS = 4; //cuatro columnas

// Las teclas del teclado matricial
char keys[ROWS][COLS] = {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};

// conecatamos el arduino con el teclado matricial!!!!
byte rowPins[ROWS] = {9, 8, 7, 6}; //conectar los pines de las filas al arduino
byte colPins[COLS] = {5, 4, 3, 2}; //conectar los pines de las columnas al arduino
String piso = "";
byte message;
int pisonumber;
// Objetos de el Teclado Matricial
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


void setup(){
    Serial.begin(9600);//Para definir la escriltura en el Monitor en Serie
    // Inicializamos la libreria Wire siempre en el setup
    Wire.begin();
}

void loop(){
    char key = keypad.getKey();

    if (key != NO_KEY){
        if (key == '*'){
            Serial.println(piso);
            pisonumber = atoi(piso.c_str());
            if (pisonumber > 0 && pisonumber <= 9){
                // Iniciamos la transmision y mandamos el dato al esclavo
                Wire.beginTransmission(1);
                Wire.write(message);
                Wire.endTransmission();
            }else{
                Wire.beginTransmission(1);
                Wire.write("0");
                Wire.endTransmission();
            }
            piso = "";
        }else{
            piso += key;    
            message = key;
        }
        Serial.println(piso);
    }
}

// ================ COLA =====================