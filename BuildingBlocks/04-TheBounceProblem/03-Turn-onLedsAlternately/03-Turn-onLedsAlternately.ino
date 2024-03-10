/*
 * The program turn-on 4 LEDs sequentially when the push button is pressed.
 */

#define PUSHBTN_PIN 8
#define LED_1_PIN 5
#define LED_2_PIN 4
#define LED_3_PIN 3
#define LED_4_PIN 2

unsigned long last_time_button_changes = millis();
unsigned long curr_time = 0; 
unsigned long debounce_delay = 30; // [ms] - put this to 0 to see the bounce problem
unsigned to_turn_on_idx = LED_1_PIN;
unsigned led_idx = LED_1_PIN;

byte prev_state = LOW;

void setup() {
  // configure serial monitor
  Serial.begin(115200);

  // configure push button
  pinMode(PUSHBTN_PIN, INPUT);

  // configure leds
  pinMode(LED_1_PIN, OUTPUT);
  pinMode(LED_2_PIN, OUTPUT);
  pinMode(LED_3_PIN, OUTPUT);
  pinMode(LED_4_PIN, OUTPUT);
}

void loop() {
  curr_time = millis();

  if (curr_time - last_time_button_changes > debounce_delay) {
    byte curr_state = digitalRead(PUSHBTN_PIN);
    if (curr_state != prev_state) {
      // update debounce dealy time 
      last_time_button_changes = curr_time;
      
      // turn-on led
      if(curr_state == HIGH) {
        Serial.println("Button Pressed!");
        turn_on_led();
      } else {
        // update next led idx number to turn-on
        led_idx--;
        if (led_idx < 2) led_idx = LED_1_PIN;
      }

      // update button state
      prev_state = curr_state;
    }
  }
}

void turn_on_led() {
  Serial.println(led_idx);
  switch (led_idx) {
    case LED_1_PIN:
      digitalWrite(LED_1_PIN, HIGH);
      digitalWrite(LED_2_PIN, LOW);
      digitalWrite(LED_3_PIN, LOW);
      digitalWrite(LED_4_PIN, LOW);
      break;
    case LED_2_PIN:
      digitalWrite(LED_1_PIN, LOW);
      digitalWrite(LED_2_PIN, HIGH);
      digitalWrite(LED_3_PIN, LOW);
      digitalWrite(LED_4_PIN, LOW);
      break;
    case LED_3_PIN:
      digitalWrite(LED_1_PIN, LOW);
      digitalWrite(LED_2_PIN, LOW);
      digitalWrite(LED_3_PIN, HIGH);
      digitalWrite(LED_4_PIN, LOW);
      break;
    case LED_4_PIN:
      digitalWrite(LED_1_PIN, LOW);
      digitalWrite(LED_2_PIN, LOW);
      digitalWrite(LED_3_PIN, LOW);
      digitalWrite(LED_4_PIN, HIGH);
      break;
  }


}
