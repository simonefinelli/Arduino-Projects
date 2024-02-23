/*
 * Simulate a Traffic Light using 3 LEDs.
 */

#define GREEN_LED_PIN 2
#define ORANGE_LED_PIN 3
#define RED_LED_PIN 4

void setup() {
  // config PINs
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(ORANGE_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
}

void loop() {
  // green light
  digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(ORANGE_LED_PIN, LOW);
  digitalWrite(GREEN_LED_PIN, HIGH);
  delay(1500);
  
  // orange light
  digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(ORANGE_LED_PIN, HIGH);
  digitalWrite(GREEN_LED_PIN, LOW);
  delay(1000);
  
  // red light
  digitalWrite(RED_LED_PIN, HIGH);
  digitalWrite(ORANGE_LED_PIN, LOW);
  digitalWrite(GREEN_LED_PIN, LOW);
  delay(2000);
}