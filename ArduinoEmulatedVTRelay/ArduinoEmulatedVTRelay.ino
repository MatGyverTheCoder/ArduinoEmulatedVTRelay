/*
 * Author: Mathew Hasting
 * Date: 10/16/21
 * Desc: Detects fault in Arduino circuit, and plays small/large announcements accordingly.
 * Credit for Pirates of the Caribbean buzzer melody: https://github.com/xitanggg/-Pirates-of-the-Caribbean-Theme-Song/blob/master/Pirates_of_the_Caribbean_-_Theme_Song.ino
 */

#include "pitches.h"

int ledPin = 12;
int buzzerPin = 2;

int faultNum = 0;

// Change to 0.5 for a slower version of the song, 1.25 for a faster version
const float songSpeed = 1.0;

// The pirates of the caribbean notes array 
int pirateNotes[] = {
    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
    NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
    NOTE_A4, NOTE_G4, NOTE_A4, 0,

    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
    NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
    NOTE_A4, NOTE_G4, NOTE_A4, 0,

    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
    NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 0,
    NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 0,
    NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 0,

    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
    NOTE_D5, NOTE_E5, NOTE_A4, 0,
    NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 0,
    NOTE_C5, NOTE_A4, NOTE_B4, 0};

int startUp[] = {
  NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};

// The note duration, 8 = 8th note, 4 = quarter note, etc.
int pirateDurations[] = {
    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 375, 125,

    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 375, 125,

    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 125, 250, 125,

    125, 125, 250, 125, 125,
    250, 125, 250, 125,
    125, 125, 250, 125, 125,
    125, 125, 375, 375};

int startDurations[] = {
  4, 8, 8, 4,4,4,4,4 };

void setup() {
  // put your setup code here, to run once:
   pinMode(ledPin, OUTPUT);
   pinMode(buzzerPin, OUTPUT);
   pinMode(buttonPin, INPUT);
   startAnnouncement();
   //musicPlayer(startUp, startDuration);
}

void loop() {
    //largeAnnouncement();
    //delay(5000);

    if(fault()) {
      faultNum++;
      if(faultNum < 2)
        smallAnnouncement();
      else
        largeAnnouncement();
      delay(1000);
    }
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
  //Flashes LED in pin 12 and plays Buzzer in pin 2
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
  const int totalNotes = sizeof(pirateNotes) / sizeof(int);
  // Loop through each note
  for (int i = 0; i < totalNotes; i++)
  {
    const int currentNote = pirateNotes[i];
    float wait = pirateDurations[i] / songSpeed;
    // Play tone if currentNote is not 0 frequency, otherwise pause (noTone)
    if (currentNote != 0)
    {
      digitalWrite(ledPin, HIGH);
      tone(buzzerPin, pirateNotes[i], wait); // tone(pin, frequency, duration)
    }
    else
    {
      digitalWrite(ledPin, LOW);
      noTone(buzzerPin);
    }
    // delay is used to wait for tone to finish playing before moving to next loop
    delay(wait);
  }
}

void startAnnouncement(){
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    // to calculate the note duration, take one second 
    int noteDuration = 1000/startDurations[thisNote];
    tone(buzzerPin, startUp[thisNote],startDurations);
    // to distinguish the notes, set a minimum time between them.
    int pauseBetweenNotes = noteDuration * 1;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(buzzerPin);
    if(thisNote % 2)
      digitalWrite(ledPin, HIGH);
    else
      digitalWrite(ledPin, LOW);
  }
  digitalWrite(ledPin, LOW);
  delay(500);
  
}

//Work on this if have time
/*void musicPlayer(int notes[], int durations[]){
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/durations[thisNote];
    tone(buzzerPin, notes[thisNote],durations);
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * songSpeed;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(buzzerPin);
  }
}*/
