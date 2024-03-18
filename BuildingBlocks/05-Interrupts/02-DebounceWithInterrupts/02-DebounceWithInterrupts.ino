/**
 * If we use Interrupts to manipulate a push button, for example, we can run into the bounce behaviour.
 * So, it is our dutyto take responsibility for managing that.
 *
 * ATTENTION: Using a debounce approach directly inside an Interrupt is NOT the best solution. If we want to avoid that,
 * a better solution is to use an harware debounce set-up (already integrated into a better quality push button).
 */

#define LED_PIN 8
#define BTN_PIN 2

// led config
byte led_state = LOW;
// interrrupt
volatile bool btn_press_flag = false;  // 'volatile' allows the modification of a variable into an interrupted function
// debounce behaviour
volatile unsigned long last_time_button_pressed = millis();
volatile unsigned long curr_time = 0;
volatile unsigned long debounce_delay = 50;

void setup() {
  // set serial communication
  Serial.begin(115200);

  // set pins
  pinMode(LED_PIN, OUTPUT);
  pinMode(BTN_PIN, INPUT);

  // define interrupt
  attachInterrupt(digitalPinToInterrupt(BTN_PIN),
                  btn_release_action,
                  FALLING); // set-up interrupt with Falling politic
}

void loop() {
  if (btn_press_flag) {
    btn_press_flag = false;
    toggle_led();
  }

}

void btn_release_action() {  // an interrupt function cannot have a return type and have parameters
  curr_time = millis();
  if (curr_time - last_time_button_pressed > debounce_delay) {
    last_time_button_pressed = curr_time; // update debounce dealy time 
    btn_press_flag = true;
  }
}

void toggle_led() {
  led_state = (led_state) ? LOW : HIGH;
  digitalWrite(LED_PIN, led_state);
}