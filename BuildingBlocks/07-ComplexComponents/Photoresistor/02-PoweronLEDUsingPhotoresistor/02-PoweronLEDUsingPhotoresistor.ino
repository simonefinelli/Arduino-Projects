/**
 * The program turn-on/off a LED based on photoresistor luminosity.
 */

// config photoresisto
#define PHOTORESISTOR_PIN A0
#define THRESHOLD 300

// config LED
#define LED_PIN 10

void setup() {
  // init led
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int luminosity = analogRead(PHOTORESISTOR_PIN);
  
  if (luminosity < THRESHOLD) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  delay(100);
}
