//used code from https://create.arduino.cc/projecthub/SBR/switching-using-transistor-c9114a
//Connected a transistor, LED, and two resistors to make the LED blink

const int transistor = 2;

void setup()
{
  pinMode (transistor, OUTPUT);
  
}

void loop()
{
  //When the transistor input is high, the circuit is on
  digitalWrite (transistor, HIGH);
  delay(2000);
//  //When the transistor input is low, the circuit is off
//  digitalWrite (transistor, LOW);
//  delay(2000);
}
