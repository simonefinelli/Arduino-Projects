/*
 * To avoid the bounce problem, we can stop to check for the state of the 
 * component - button in this case - in a defined intervall (typically 30-50 ms) 
 * in order to avoid pysical oscillations.
 */

#define PUSHBTN_PIN 3

unsigned long last_time_button_changes = millis();
unsigned long curr_time = 0; 
unsigned long debounce_delay = 30; // [ms] - put this to 0 to see the bounce problem in monitor's logs

byte prev_state = LOW;

void setup() {
  Serial.begin(115200);

  pinMode(PUSHBTN_PIN, INPUT);
}

void loop() {
  curr_time = millis();

  if (curr_time - last_time_button_changes > debounce_delay) {
    byte curr_state = digitalRead(PUSHBTN_PIN);
    if (curr_state != prev_state) {
      // update debounce dealy time 
      last_time_button_changes = curr_time;
      // do somethig with button pressing
      prev_state = curr_state;
      if(curr_state == HIGH) {
        Serial.println("Button Pressed!");
      } else {
        Serial.println("Button Released!");
      }
  }
  }


}
