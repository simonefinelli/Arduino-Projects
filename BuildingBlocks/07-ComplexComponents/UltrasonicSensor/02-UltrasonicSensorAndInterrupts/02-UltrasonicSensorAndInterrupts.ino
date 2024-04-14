/**
 * Using pulseIn() will take more or less time to measure the distance of
 * an object from the sensor (more distance -> more time), blocking the program.
 * That behaviour is not acceptable when we have to handle more 
 * ultrasonic sensors in one architecture.
 * 
 * To avoid that we can use interrupts: using iterrupts we can simulate the job done by pulseIn().
 */

#define ECHO_PIN 3
#define TRIGGER_PIN 4

unsigned long last_time_trigget = millis();  // trig the ultrasonic sensor time
unsigned long ultrasonic_delay = 100; // [ms] - listening time

volatile unsigned long pulsein_time_begin;
volatile unsigned long pulsein_time_end;
volatile bool new_distance_available_flag = false;

void setup() {
  // serial monitor
  Serial.begin(115200);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIGGER_PIN, OUTPUT);

  // set-up interrupt
  attachInterrupt(digitalPinToInterrupt(ECHO_PIN),
                  echo_pin_interrupt,
                  CHANGE);  // this mode detects the change of signal status from low to hight and viceversa

}

void loop() {
  unsigned long curr_time = millis();

  if (curr_time - last_time_trigget > ultrasonic_delay) {
    last_time_trigget += ultrasonic_delay;
    // trigger the ultrasonic sensor
    trig_ultranosic_sensor();

    // read pulse on echo pin
    if (new_distance_available_flag) {
      new_distance_available_flag = false;
      
      double distance = get_distance();
      Serial.println(distance);
    }
  }
}

/**
 * The function changes the sensor's status to HIGH for 10µs.
 */
void trig_ultranosic_sensor() {
  // reset status of sensor (just as a precaution)
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);

  // emit the pulse
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
}

/**
 * The function reads from ECHO pin to get data from the sensor and convert
 * it into a readable distance.
 * 
 * Returns the distance in cm.
 */
double get_distance() {
  unsigned long pulsein_start = micros();
  // unsigned long duration = pulseIn(ECHO_PIN, HIGH);  // using HIGH MODE - the function return the duration in µs.
  unsigned long duration = pulsein_time_end - pulsein_time_begin; // NOTE: now the duration is always (with different distances)!
  unsigned long pulsein_end = micros();
  Serial.println("The duration of punseIn() in microseconds is: " + String(pulsein_end - pulsein_start));

  // distance = duration * speed (sound in air in this case - 340m/s --> 0.034 cm/µs)
  // duration * (0.034 / 2) (the wawe run across two time - forward and backward)
  // the line above can be replaces with constant 58 or 148!
  double distance = double(duration) / 58.0;  // [cm] - (148.0: inches)
  return distance;
}

/**
 * This function will call every time we have a signal change on ECHO PIN
 * (interrupt setted on CHANGE mode).
 *
 * The function allows us to measure the time instance when the signal on ECHO PIN
 * is rising or falling.
 */
void echo_pin_interrupt() {
  if (digitalRead(ECHO_PIN) == HIGH) {
    // rising signal (low to high)
    pulsein_time_begin = micros();
  } else {
    // falling signal (high to low)
    pulsein_time_end = micros();
    new_distance_available_flag = true;
  }
}
