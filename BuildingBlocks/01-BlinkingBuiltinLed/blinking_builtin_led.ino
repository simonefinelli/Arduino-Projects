/* Make the build-in LED blinking with these contraints:
 * - Power-on for 2 seconds
 * - Power-off for 1 second
 *
 * Use Serial Monitor to create logs.
 */

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);  // init digital pin
  Serial.begin(9600);            // init serial monitor with 9600 bit-rate
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("Built-in LED ON!");
  delay(2000);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("Built-in LED OFF!");
  delay(1000);
}
