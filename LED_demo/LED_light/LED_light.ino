void setup() {
  pinMode(8, OUTPUT);
}
void loop() {
//uses code from https://www.circuitbasics.com/arduino-basics-controlling-led/
//to light up and blink a LED from pin 8
//I used a 220 ohm resistor and a red LED
  digitalWrite(8, HIGH);   
  delay(1000);              
  digitalWrite(8, LOW);   
  delay(1000);             
}
