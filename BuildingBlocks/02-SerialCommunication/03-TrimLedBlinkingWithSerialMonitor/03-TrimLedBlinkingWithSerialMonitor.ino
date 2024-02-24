/**
 * Trim the LED blinking using a rate sending on Serial comminication.
 */

#define LED_PIN 2

long delay_time = 1000;
long buffer = 0;

void setup() {
  // set-up serial communication
  Serial.begin(115200);  // [bps]
  Serial.setTimeout(10);  // [ms]
  Serial.println("Communication Enabled");

  // set-up led
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // read new delay command using communication

  if (Serial.available() > 0) {
    buffer = Serial.parseInt();

    if (buffer >= 50 && buffer <= 2000) {
      Serial.println("Delay: " + String(buffer));
      delay_time = buffer;
    } else {
      // if we send different values from integers
      Serial.println("Delay: " + String(100));
      delay_time = 100;
    }
  }

  digitalWrite(LED_PIN, LOW);
  delay(delay_time);

  digitalWrite(LED_PIN, HIGH);
  delay(delay_time);
}
