/**
 * The programs counts the number of time that a push button is pressed,
 * using Interrupts.
 */

#define BTN_PIN 2

// led config
byte led_state = LOW;
// interrrupt
volatile bool btn_press_flag = false;
volatile unsigned long counter = 0;  // 'volatile' allows the modification of a variable into an interrupted function
// debounce behaviour
volatile unsigned long last_time_button_pressed = millis();
volatile unsigned long curr_time = 0;
volatile unsigned long debounce_delay = 100;

void setup() {
  // set serial communication
  Serial.begin(115200);

  // set pin
  pinMode(BTN_PIN, INPUT);

  // define interrupt
  attachInterrupt(digitalPinToInterrupt(BTN_PIN),
                  btn_release_action,
                  FALLING); // set-up interrupt with Falling politic
}

void loop() {
  if (btn_press_flag) {
    btn_press_flag = false;
    Serial.println("The Button is pressed for " + String(counter) + " times!");
  }

}

void btn_release_action() {  // an interrupt function cannot have a return type and have parameters
  curr_time = millis();
  if (curr_time - last_time_button_pressed > debounce_delay) {
    last_time_button_pressed = curr_time; // update debounce dealy time 
    btn_press_flag = true;
    counter++;
  }
}