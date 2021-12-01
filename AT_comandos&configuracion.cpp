void setup() {
  Serial.begin(9600);
  Serial.println("Comunicacion Iniciada");
  Serial1.begin(38400);
}

void loop() {
  //COMANDO AT (?)
  if(Serial1.available()>0){ //Si el Módulo Bluetooth envia informacion 
      Serial.write(Serial1.read()); //Se escribe en el monitor en serie, lo que envia el Modulo
    }
    //COMANDOS AT(=)
  if(Serial.available()>0){// Si el Monitor en Serie envia informacion
      Serial1.write(Serial.read()); // Se escribe en el modulo Bluetooth
    }

}