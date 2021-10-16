#include <avr/sleep.h>
int x;
void setup() {
  // see below for sleep modes
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  x = 10;
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(200);  
  digitalWrite(LED_BUILTIN, LOW);
  delay(200);
  x--; // blink the LED a few more times before sleeping
  if (x > 0) return;
  sleep_mode();
}
