/**
 * The program turn-on/off a LED using a potentiometer.
 * The max intensity value of the led is read from EEPROM.
 * The value can be changed by using the user's input from
 * the Serial Monitor.
 */

#include <EEPROM.h>

#define LED_PIN_1 3
#define POTENTIOMETER_PIN A5
#define DELAY 100

unsigned long previous_time = 0;
unsigned long curr_time = millis();
unsigned max_led_brightness;

void setup() {
  // configure serial monitor
  Serial.begin(115200);  // [bps]
  Serial.setTimeout(10);  // [ms]
  
  // configure led and potentiomenter
  pinMode(LED_PIN_1, OUTPUT);
  // REMEMBER: Analog IN pin must not be initialize with pinMode()
  
  // set led brighteness using stored default settigs
  max_led_brightness = EEPROM.read(0);
  analogWrite(LED_PIN_1, led_brightness);
}

void loop()
{
  // user input
  curr_time = millis();
  if ((curr_time - previous_time) > DELAY) {  // async user input check
    if (Serial.available() > 0) { // check serial monitor data
      buffer = Serial.parseInt();
      if (buffer >= 125 && buffer <= 255) {
        Serial.println("Max Intensity default value updated to: " + String(buffer));
        EEPROM.write(0, buffer);  // store new default value into EEPROM att address 0x00
      } else {
        Serial.println("Value must be in the range 125-255!");
      }
    previous_time += DELAY;
  }
  
  // Potentimeter
  int led_brightness = int(analogRead(POTENTIOMETER_PIN) * 0.25);
  if (led_brightness <= max_led_brightness
  	analogWrite(LED_PIN_1, led_brightness);  // 100 to 0% of 5v
  
  
  delay(100);  // 10Hz
}
