/**
 * Make a LED blinking with these contraints:
 *  - Use a Digital Port (12 in this case) to connect the LED to Arduino.
 *  - Turn on the LED for 3 seconds at the starts.
 *  - Then make it blink with a delay of 0.8 seconds.
 *  - Use Serial Monitor to create logs.
 */

#define LED_PIN 12

void setup() {
  pinMode(LED_PIN, OUTPUT);  // OUTPUT -> set(change) state
  digitalWrite(LED_PIN, HIGH);  // HIGH -> 5V
  delay(3000);  // [ms]
}

void loop() {
  digitalWrite(LED_PIN, LOW); // LOW -> 0V
  delay(800);

  digitalWrite(LED_PIN, HIGH);
  delay(800);
}
