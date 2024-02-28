/**
 * Delay() function in many cases cannot be used beause it is a blocking function.
 * 
 * To deal with that behaviour we can use time functions (millis() and micros()) to obtain
 * a non-blocking behaviour.
 *
 * In this examples, for example, we simulate a dalay of 500ms using millis().
 */

#define DELAY 500

unsigned long previous_time = 0;
unsigned long curr_time = millis();

void setup() {
  Serial.begin(115200);

}

void loop() {
  curr_time = millis();
  if ((curr_time - previous_time) > DELAY) {
    Serial.println("Async Hello World!");
    previous_time += DELAY;  // instead of curr_time we use DELAY value to avoid that 
                             // the time taken by other instructions are not included 
                             // in the delay count
    Serial.println(millis());
  }
}
