/**
 * Set the brightness of a LED using a Digital PIN as Analog one.
 * 
 * Some Digital PINs can be used as Analog one (~), using PWM technique.
 * PWM (Pulse Width Modulation) is a technique used to generate analog-like signals using digital devices, 
 * allowing you to simulate analog output levels by varying the duty cycle of a square wave.
 * Duty cycle represents the percentage of time the signal is HIGH in one period.
 * A 50% duty cycle means the signal is HIGH half of the time.
 * The duty cycle in Arduino is expressed using 0-255 range,
 * so to apply the 25% duty cycle we have to use the number 64.

 */

#define LED_PIN 11

void setup() {
  pinMode(LED_PIN, OUTPUT); // PIN 11 can be used as analog
  digitalWrite(LED_PIN, HIGH);
  delay(2000);  // [ms]
}

void loop() {
  // change brightness of the LED using Analog Signal
  analogWrite(LED_PIN, 0);  // 0% of 5v
  delay(1500);
  analogWrite(LED_PIN, 127);  // 50% of 5v
  delay(1500);
  analogWrite(LED_PIN, 255);  // 100% of 5v
  delay(1500);
}