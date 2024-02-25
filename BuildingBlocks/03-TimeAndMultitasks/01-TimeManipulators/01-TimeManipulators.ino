/**
 * To manupulate the time in Arduino programs we can use 
 * delay() and delayMicroseconds() functions.
 */

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.println("Wait for 1 second!");
  delay(1000);  // 1s delay - delay now is expressed in ms
  Serial.println("Wait for 0.01 second!");
  delayMicroseconds(1000);  // 1s delay - delay now is ecpressed in µs
}
