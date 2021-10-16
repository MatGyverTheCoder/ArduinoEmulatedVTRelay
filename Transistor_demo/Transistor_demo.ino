//used code from https://create.arduino.cc/projecthub/SBR/switching-using-transistor-c9114a
//Connected a transistor, LED, and two resistors to make the LED blink

const int transistor = 2;

void setup()
{
  pinMode (transistor, OUTPUT);
  
}

void loop()
{
  digitalWrite (transistor, HIGH);
  delay(1000);
  digitalWrite (transistor, LOW);
  delay(1000);
}
