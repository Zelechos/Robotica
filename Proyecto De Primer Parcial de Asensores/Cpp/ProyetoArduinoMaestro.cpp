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
char opc;
int pisonumber = 0;
// Objetos de el Teclado Matricial
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


void setup(){
    Serial.begin(9600);//Para definir la escriltura en el Monitor en Serie
}

void loop(){
    char key = keypad.getKey();

    if (key != NO_KEY){
        if (key == '*'){
            pisonumber = atoi(piso.c_str());
            if (pisonumber > 0 && pisonumber <= 33){
                Serial.println("piso existe");
            }else{
                Serial.println("piso NO EXISTE!!!!");
            }
            piso = "";
        }else{
            piso += key;    
        }
        Serial.println(piso);
    }
}

// ================ COLA =====================