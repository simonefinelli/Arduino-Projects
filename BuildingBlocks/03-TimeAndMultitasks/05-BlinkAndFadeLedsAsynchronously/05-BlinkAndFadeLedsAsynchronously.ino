/**
 * Blinking LEDs asynchronously using time functions (with delay() could be impossible!).
 * Constraints:
 *  - LED1 must blink at 500ms
 *  - LED2 must fade-in/fade-out in 2560ms
 */

#define LED_1_PIN 2
#define LED_2_PIN 3
#define DELAY_1 500
#define DELAY_2 5

unsigned long prev_t1 = millis();
unsigned long curr_t1 = 0;

unsigned long prev_t2 = millis();
unsigned long curr_t2 = 0;

// prototypes
void blink_led();
void fade_in_out_led();

void setup() {
  // initializa serial communication
  Serial.begin(115200);

  // configure and initialize leds
  pinMode(LED_1_PIN, OUTPUT);
  pinMode(LED_2_PIN, OUTPUT);  // used as analog
  digitalWrite(LED_1_PIN, LOW);
  analogWrite(LED_2_PIN, 0);
}

void loop() {
  curr_t1 = millis();
  if ((curr_t1 - prev_t1) > DELAY_1) {
    blink_led();
    prev_t1 += DELAY_1;
  }

  curr_t2 = millis();
  if ((curr_t2 - prev_t2) > DELAY_2) {
    fade_in_out_led();
    prev_t2 += DELAY_2;
  }
}

/**
 * The function change every time it is called the led's status.
 */
void blink_led() {
  Serial.println("Set led Volt to: " + String(digitalRead(LED_1_PIN)));
  digitalRead(LED_1_PIN) ? digitalWrite(LED_1_PIN, LOW) : digitalWrite(LED_1_PIN, HIGH);
}

/**
 * The function create a full fade-in/fade-out cycle effect step by step during time.
 */
void fade_in_out_led() {
  Serial.println("Start fade-in/fade-out");
  static uint8_t analog_value = 0;
  static bool flag = false;

  // set intensity using current analog_value
  analogWrite(LED_2_PIN, analog_value);  // 0% to 100% of 5v

  // update intensity
  flag = (analog_value == 255) ? true : (analog_value == 0) ? false : flag;
  analog_value = flag ? analog_value - 1 : analog_value + 1;
}
