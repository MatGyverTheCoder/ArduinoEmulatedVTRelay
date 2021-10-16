

const int transistor = 7; //change to correct pin number 
bool Fault = false; //Default no fault

void setup() {

  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200); //check baud rate in ctr-shift-M

  //set up the transistor (Base input)
  pinMode (transistor, OUTPUT);

  //Turn on the circuit via transistor
  TurnOn();

  //get two readings of the voltage
  delay(200);
  DetectFault();
  delay(200);
  DetectFault();
  delay(200);
  
  TurnOff();
  delay(2000);


}

void loop() {

}


//////////// User defined functions ////////////

void TurnOn()
{
  digitalWrite (transistor, HIGH);
}

void TurnOff()
{
  digitalWrite (transistor, LOW);
}

//void DetectVoltage
void ReadAnalogVoltage()
{
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  Serial.println(voltage);
}

void DetectFault()
{
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  Serial.println(voltage);
  if (voltage < 2) {
    Fault = true;
  } else {
    Fault = false;
  }
  Serial.println(Fault);
}
