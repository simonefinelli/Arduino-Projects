/**
 * One way to get the time in an Arduino board is to use the functions
 * millis() and micros().
 * 
 * ATTENTION: These kind of functions return the time since the Arduino is powered on!
 */

unsigned long curr_time = 0;

void setup() {
  Serial.begin(115200);
  
  unsigned long start_time = millis();  // time in milliseconds
  Serial.println(start_time);

}

void loop() {
  delay(500);
  curr_time = millis();
  Serial.println(curr_time);
}
