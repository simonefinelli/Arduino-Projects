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
 */


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
