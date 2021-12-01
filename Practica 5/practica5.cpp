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

void setup(){
    Serial.begin(9600);
    for (byte i = 2; i <= 8; i++){
        pinMode(i, OUTPUT);
    }
    sevenSegments(4);
}

void loop() {
  // put your main code here, to run repeatedly:

}

//metodo para el manejo de los numeros
void sevenSegments(byte num){
  for(byte i= 0; i <= 7 ; i++){
    digitalWrite(i+2 , number[num][i]);  
  }
}