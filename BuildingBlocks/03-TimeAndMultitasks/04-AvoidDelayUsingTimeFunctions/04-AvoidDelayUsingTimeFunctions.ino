/**
 * Delay() function in many cases cannot be used beause it is a blocking function.
 * 
 * To deal with that behaviour we can use time functions (millis() and micros()) to obtain
 * a non-blocking behaviour.
 *
 * In this examples, for example, we simulate a dalay of 500ms using millis().
 */

unsigned long previous_time = millis();
unsigned long curr_time = 0;

void setup() {
  Serial.begin(115200);

}

void loop() {
  curr_time = millis();
  if ((curr_time - previous_time) > 500) {
    Serial.println("Hello");
    previous_time = curr_time;
  }
}
