/**
 * In this program we turn-on 3 different leds using the distance read by the ultrasonic sensor:
 *  - 0.00-19.99cm: turn-on yellow led;
 *  - 20.00-39.99cm: turn-on green led;
 *  - >40.00cm: turn-on red led.
 *
 * Also we print on the LCD screen the distance.
 */

#include <LiquidCrystal.h>

/// LCD configuration
#define LCD_RS_PIN A5
#define LCD_E_PIN A4
#define LCD_D4_PIN 6
#define LCD_D5_PIN 7
#define LCD_D6_PIN 8
#define LCD_D7_PIN 9

// the size of the screen is expressed like a matrix
#define LCD_WIDTH 16
#define LCD_HEIGHT 2

// init LCD display
LiquidCrystal lcd(
  LCD_RS_PIN,
  LCD_E_PIN,
  LCD_D4_PIN,
  LCD_D5_PIN,
  LCD_D6_PIN,
  LCD_D7_PIN
);

/// LEDs config

#define LED_1_PIN 10
#define LED_2_PIN 11
#define LED_3_PIN 12
#define ECHO_PIN 3
#define TRIGGER_PIN 4
#define MAX_DISTANCE 400

char formatted_str[17];  // formatted string to show distance on lcd

/// ultrasonic sensor config
unsigned long last_time_trigget = millis();  // trig the ultrasonic sensor time
unsigned long ultrasonic_delay = 100; // [ms] - listening time
unsigned led_status[3] = {0};  // handle on-off of leds
volatile unsigned long pulsein_time_begin;
volatile unsigned long pulsein_time_end;
volatile bool new_distance_available_flag = false;
// to avoid reading incorrect value from the sensor (especially in cheaper one)
double previus_distance = MAX_DISTANCE; // [cm]

void setup() {
  // serial monitor
  Serial.begin(115200);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIGGER_PIN, OUTPUT);

  // leds
  pinMode(LED_1_PIN, OUTPUT);
  pinMode(LED_2_PIN, OUTPUT);
  pinMode(LED_3_PIN, OUTPUT);

  // set-up interrupt
  attachInterrupt(digitalPinToInterrupt(ECHO_PIN),
                  echo_pin_interrupt,
                  CHANGE);  // this mode detects the change of signal status from low to hight and viceversa
  
  // init LCD
  lcd.begin(LCD_WIDTH, LCD_HEIGHT);
  lcd.print("UltrasonicSensor");

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
      // print distance on lcd
      lcd.setCursor(0, 1);
      sprintf(formatted_str, "Distance: %03d cm", int(distance));
      lcd.print(formatted_str);

      if (distance <= 20) {
        led_status[0] = HIGH;
      } else if (distance <= 40) {
        led_status[1] = HIGH;
      } else {
        led_status[2] = HIGH;  
      }

      digitalWrite(LED_1_PIN, led_status[0]);
      digitalWrite(LED_2_PIN, led_status[1]);
      digitalWrite(LED_3_PIN, led_status[2]);

      // reset status array
      memset(led_status, 0, sizeof(led_status));
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
  if (distance > MAX_DISTANCE) {
    return previus_distance;
  }
  distance = previus_distance * 0.70 + distance * 0.30; // complementary filter: an average between the previose distance and the current distance. - to get a smoother value reading
                                                        // tip: adjust the two scalars to change the contribution
  previus_distance = distance;
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
