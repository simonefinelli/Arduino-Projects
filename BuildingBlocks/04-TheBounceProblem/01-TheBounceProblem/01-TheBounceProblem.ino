/*
 * The bounce problem occours with changes of states, like in the push button behaviour 
 * (push and release -> high to low voltage).
 * The bounce problem is not else that the record of an action multiple times, even if it is done
 * only one time. This behaviour is purely due to physical component.
 * This figure can help: https://rb.gy/b77nqm.
|* 
 * For Example, if we try to detect the button pressing and releasing in a simple way, sometime (when 
 * we press and realse the button) we can obtain multiple hits.
 */

#define PUSHBTN_PIN 3

byte prev_state = LOW;

void setup() {
  Serial.begin(115200);

  pinMode(PUSHBTN_PIN, INPUT);
}

void loop() {
  byte curr_state = digitalRead(PUSHBTN_PIN);

  if (curr_state != prev_state) {
    prev_state = curr_state;
    if(curr_state == HIGH) {
      Serial.println("Button Pressed!");
    } else {
      Serial.println("Button Released!");
    }
  }

}
