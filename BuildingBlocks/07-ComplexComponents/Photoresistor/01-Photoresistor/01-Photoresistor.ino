/**
 * The Photoresistor is used to detect the luminosity of the environment.
 */

#define PHOTORESISTOR_PIN A0

void setup() {
  // init serial communication
  Serial.begin(115200);
  // the photoresistor is connected to an analog pin, so no need to initialize it!
}

void loop() {
  Serial.println(analogRead(PHOTORESISTOR_PIN));

  delay(100);
}