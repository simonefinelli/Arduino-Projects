/**
 * The program allow the user to blink 3 LEDs using:
 *  - Serial Communication: the user can decide the bliking rate (in ms) of the first using the Serial Monitor;
 *  - Potentiometer: the user can manipulate the brightness of the second led;
 *  - Push Button: the user can turn on the third led.
 *
 * TIP: all these actions can be done in asynchronous mode!
 */

#define LED_1_PIN 4
#define LED_2_PIN 3
#define LED_3_PIN 2
#define POTENTIOMETER_PIN A5
#define PUSHBTN_PIN 5

unsigned delay_rate = 500; // [ms]
unsigned long prev_t = millis();
unsigned long curr_t = 0;
unsigned user_choice = 0;

void setup() {
  // configure serial communication
  Serial.begin(115200);
  Serial.setTimeout(10); // reading wait time [ms]

  // configure leds
  pinMode(LED_1_PIN, OUTPUT);
  digitalWrite(LED_1_PIN, LOW);
  pinMode(LED_2_PIN, OUTPUT);
  analogWrite(LED_2_PIN, 0);
}

void loop() {
  curr_t = millis();

  // led 1 behaviour
  blink_led_1();

  // led 2 behaviour
  fade_led_2();

  // led 3 behaviour
  activate_led_3();

  delayMicroseconds(10000); // 10ms - some dalay to moderate the velocty of the board
}

/**
 * The function update the Led1's refresh rate using the user input in Serial Monitor.
 */
void blink_led_1() {
  // get user input
  if (Serial.available() > 0) {
    user_choice = Serial.parseInt();
    if (user_choice >= 50 and user_choice <= 5000) {
      delay_rate = unsigned(user_choice);
      Serial.println("Delay Time updated: " + String(delay_rate) + "ms");
    } else {
      Serial.println("Delay Time must be in 50-5000ms range!");
    }
  }

  // check and change led1's status
  if ((curr_t - prev_t) > delay_rate) {
    digitalRead(LED_1_PIN) ? digitalWrite(LED_1_PIN, LOW) : digitalWrite(LED_1_PIN, HIGH);
    prev_t += delay_rate;
  }
}

/**
 * The function 
 */
void fade_led_2() {
  // transfor potentiometer's values to LED range values
  analogWrite(LED_2_PIN, int(analogRead(POTENTIOMETER_PIN) * 0.25));  // 100 to 0% of 5v
}

void activate_led_3() {
  digitalRead(PUSHBTN_PIN) ? digitalWrite(LED_3_PIN, HIGH) : digitalWrite(LED_3_PIN, LOW);
}