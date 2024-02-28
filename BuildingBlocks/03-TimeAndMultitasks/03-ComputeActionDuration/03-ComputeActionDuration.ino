/**
 * Compute the duration of an Action is useful to:
 *  - Debug the code;
 *  - Measure the performace;
 *  - ...
 */

void setup() {
  Serial.begin(115200);
  
  unsigned long start_time = millis();
  delay(500);
  unsigned long end_time = millis();
  auto duration = end_time - start_time; 

  Serial.println("The duration of the action is: " + String(duration));
}

void loop() {
  

}
