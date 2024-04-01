/**
 * A Ultrasonic Sensor can be used to detect the distance of an object.
 * There are multiple ultrasonic sensor on the marketl. Here we'are utilizing the HC-SR04.
 *
 * The HC-SR04 has 4 pins:
 *  - VCC: Power (5v);
 *  - GND: Ground;
 *  - TRIG: to trig the sensor (output mode) - digital pin;
 *  - ECHO: receive the data (to get the distance).
 * 
 * ATTENTION: ECHO pin must be connected to an Interrupt pin!
 *
 * Each sensor have its characteristics, for example this one can detect an object from 2cm to 400cm,
 * with a angle of 15 degree.
 *
 * How does an Ultrasonic Sensor work?
 * To start measuring the distance we have to send an high-signal (10 µs) on TRIG pin. After that,
 * the sensor will start measure the distance (with active measurement: Sonic Burst), and with the
 * ECHO pin we can monitor the high-signal (wawes received) duration in proportion to the distance of 
 * an object.
 *
 * In Arduino, we can use pulseIn() to check that behaviour:
 *  - Step 1. pulseIn() call: start measuring;
 *  - Step 2. than pulseIn() enters in waiting mode (as long as the signal is low);
 *  - Step 3. when we have a signal rising (on echo pin) the pulseIn() starts measuring the signal duration;
 *  - Step 4. when signal goes back to low, the pulseIn() returns the pulse duration in µs;
 *
 * We described a typical HIGH mode setup, but we can redefine that steps using a LOW mode setup by reverse
 * the high and low states.
 * NOTE: the HIGH/LOW mode depends on the sensor. HC-SR04 uses HIGH mode!
 */

#define ECHO_PIN 3
#define TRIGGER_PIN 4

unsigned long last_time_trigget = millis();  // trig the ultrasonic sensor time
unsigned long ultrasonic_delay = 100; // [ms] - listening time

void setup() {
  // serial monitor
  Serial.begin(115200);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIGGER_PIN, OUTPUT);

}

void loop() {
  unsigned long curr_time = millis();

  if (curr_time - last_time_trigget > ultrasonic_delay) {
    last_time_trigget += ultrasonic_delay;
    // trigger the ultrasonic sensor
    trig_ultranosic_sensor();

    // read pulse on echo pin
    Serial.println(get_distance());
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
  unsigned long duration = pulseIn(ECHO_PIN, HIGH);  // using HIGH MODE - the function return the duration in µs.

  // distance = duration * speed (sound in air in this case - 340m/s --> 0.034 cm/µs)
  // duration * (0.034 / 2) (the wawe run across two time - forward and backward)
  // the line above can be replaces with constant 58 or 148!
  double distance = double(duration) / 58.0;  // [cm] - (148.0: inches)
  return distance;
}





