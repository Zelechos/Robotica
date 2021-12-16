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


void setup(){
    Serial.begin(9600);

    // manejo de pines del siete segmentos   
    for (byte i = 2; i <= 8; i++){
        pinMode(i, OUTPUT);
    }
}

void loop(){
    //  obtenemos la distancia del ultrasonico
    long distance = 0.01723 * readUltrasonicDistance(12, 13);

    if(distance < 30){
      Serial.print("Distancia ");
      Serial.print(distance);
      Serial.println(" cm");
      count++;

      //  mostramos los numeros en el siete segmentos
      sevenSegments(count);
      if(count == 9){
        count = 0;
      }
    }
    
    delay(1000);
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
