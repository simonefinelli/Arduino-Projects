/**
 * Change the blinking rate of a LED using the user input on serial 
 * communication channel.
 * 
 * TIP: to prevent the program from freezing (due to LED delay between the 
 * on/off states), we will use time function to compute in parallel the two
 * steps (blinking - user input).
 */

#define LED_1_PIN 2

unsigned delay_rate = 500; // [ms]
unsigned long prev_t = millis();
unsigned long curr_t = 0;
unsigned user_choice = 0;

void setup() {
  // configure serial communication
  Serial.begin(115200);
  Serial.setTimeout(10); // buffer time [ms]

  // configure led
  pinMode(LED_1_PIN, OUTPUT);
  digitalWrite(LED_1_PIN, LOW);
}

void loop() {
  curr_t = millis();

  // update delay time
  if (Serial.available() > 0) {
    user_choice = Serial.parseInt();
    if (user_choice >= 50 and user_choice <= 5000) {
      delay_rate = unsigned(user_choice);
      Serial.println("Delay Time updated: " + String(delay_rate) + "ms");
    } else {
      Serial.println("Delay Time must be in 50-5000ms range!");
    }
  }
  

  // blink led at current delay rate
  if ((curr_t - prev_t) > delay_rate) {
    blink_led();
    prev_t += delay_rate;
  }

}

/**
 * The function change every time it is called the led's status.
 */
void blink_led() {
  digitalRead(LED_1_PIN) ? digitalWrite(LED_1_PIN, LOW) : digitalWrite(LED_1_PIN, HIGH);
}
