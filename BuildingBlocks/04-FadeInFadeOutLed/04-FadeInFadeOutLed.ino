/*
 * Make LEDs fading in/out using the analog signal.
 */

#define LED_PIN 3

void setup() {
  pinMode(LED_PIN, OUTPUT);
  
}

void loop() {
  // fade-in
  for (int i=0; i <= 255; i++) {
    analogWrite(LED_PIN, i);  // 0% to 100% of 5v
    delay(10);
  }
  
  // fade-out
  for (int i=255; i >= 0; i--) {
    analogWrite(LED_PIN, i);  // 100% to 0% of 5v
    delay(10);
  }
  
  delay(500);
}
