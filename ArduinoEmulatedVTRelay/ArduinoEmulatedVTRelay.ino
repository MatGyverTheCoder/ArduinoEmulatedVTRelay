
int ledPin = 12;
int buttonPin = 7;
int buzzerPin = 2;

void setup() {
  // put your setup code here, to run once:
   pinMode(ledPin, OUTPUT);
   pinMode(buzzerPin, OUTPUT);
   pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*int pushed = digitalRead(buttonPin);  // read input value
  if (pushed == HIGH) // check if the input is HIGH    
    digitalWrite(ledPin, HIGH);  // turn LED OFF
  else
    digitalWrite(ledPin, LOW);*/
    smallAnnouncement();
    delay(1000);
}

//Detects fault
bool fault() {
 //Set VA (voltage)
 //if VA is not in acceptable range, detect fault
 //true, if fault detected
 //false, if fault is not detected
 return false;
}

void smallAnnouncement() {
  for (int i = 0; i < 2; ++i){
    tone(buzzerPin, 1000);
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
    delay(100);
  }
}

void largeAnnouncement(){

}
