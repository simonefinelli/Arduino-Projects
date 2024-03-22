/**
 * The programs counts the number of time that a push button is pressed,
 * using Interrupts.
 */

#define BTN_PIN 2

unsigned long counter = 0;  // 'volatile' allows the modification of a variable into an interrupted function
// interrrupt
volatile bool btn_press_flag = false;
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
                  btn_press_action,
                  RISING); // set-up interrupt with Rising politic
}

void loop() {
  if (btn_press_flag) {
    btn_press_flag = false;
    counter++;
    Serial.println("The Button is pressed for " + String(counter) + " times!");
  }

}

void btn_press_action() {  // the function raised by interrupt must be as streamlined as possible
  curr_time = millis();
  if (curr_time - last_time_button_pressed > debounce_delay) {
    last_time_button_pressed = curr_time; // update debounce dealy time 
    btn_press_flag = true;
  }
}
