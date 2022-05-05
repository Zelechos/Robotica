int red = 12;//D6
int yellow = 13;//D7
int green = 15;//D8

void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() {
  led_activate(green);
  led_activate(yellow);
  led_activate(red);
}

void led_activate(int led){
  digitalWrite(led, HIGH);
  delay(6000);
  digitalWrite(led, LOW);
}
