/**
 * Interrupts allow the programmer to interrupt the program and execute some action.
 * Only when the Function has finished her job, the program continues.
 * 
 * There are 4 types of interrupts:
 *  - RISING: when signal goes from Low to High (Button is pressed)
 *  - FALLING: when signal goes from High to Low (Button is released)
 *  - CHANGE: Rising <-> Falling
 *  - LOW: Whenever the signal is Low
 * 
 * In Arduino, Interrupts can be used only with Digital Pins and specific ones.
 * For example in Arduino Uno we can use 2 and 3 pins.
 *
 * An interrupt function cannot have a return type and have parameters.
 * We must avoid to use Serial communication (like Serial.println()) 
 * inside an interrupt function (it will not work).
 */

#define LED_PIN 8
#define BTN_PIN 2

byte led_state = LOW;
volatile bool btn_release_flag = false;  // volatile is used to access the variable into an interrupted function

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BTN_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(BTN_PIN),
                  btn_release_action,
                  FALLING); // set-up interrupt with Falling politic
}

void loop() {
  if (btn_release_flag) {
    btn_release_flag = false;
    toggle_led();
  }

}

void btn_release_action() {
  btn_release_flag = true;
}

void toggle_led() {
  led_state = (led_state) ? LOW : HIGH;
  digitalWrite(LED_PIN, led_state);
}
