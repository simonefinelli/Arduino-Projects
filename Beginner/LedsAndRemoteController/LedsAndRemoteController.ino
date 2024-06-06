/**
 * The program uses a remote control to manage 3 LED lights.
 *
 * In detail, the useful buttons in this case are mapped below:
 *  - Button 0 -> turns off all the LEDs
 *  - Button 1 -> toggles LED 1
 *  - Button 2 -> toggles LED 2
 *  - Button 3 -> toggles LED 3
 *  - Button Stop -> cleans the LCD
 *
 */

#include <IRremote.hpp>

#define IR_RECEIVE_PIN 5
#define LED_1_PIN 10
#define LED_2_PIN 11 
#define LED_3_PIN 12

unsigned led_status[3] = {0};  // handle on-off of leds

enum IdBtns {
  STOP = 0x47,
  ZERO = 0x16,
  ONE = 0xC,
  TWO = 0x18,
  THREE = 0x5E
};

void setup() {
  // init serial communication
  Serial.begin(115200);
  // init the IR receiver
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  // init leds
  pinMode(LED_1_PIN, OUTPUT);
  pinMode(LED_2_PIN, OUTPUT);
  pinMode(LED_3_PIN, OUTPUT);
}

void loop() {
  // check data from sensor
  if (IrReceiver.decode()) {
    uint16_t command = IrReceiver.decodedIRData.command;
  
    switch (command) {
      case STOP:
        Serial.println("Pressed STOP button!");
        break;
      case ZERO:
        Serial.println("Pressed ZERO button!");
        led_status[0] = LOW;
        led_status[1] = LOW;
        led_status[2] = LOW;
        break;
      case ONE:
        Serial.println("Pressed ONE button!");
        led_status[0] = HIGH;
        break;
      case TWO:
        Serial.println("Pressed TWO button!");
        led_status[1] = HIGH;
        break;
      case THREE:
        Serial.println("Pressed THREE button!");
        led_status[2] = HIGH;
        break;
      default:
        Serial.println("Invalid data!");
    }
    IrReceiver.resume(); // enable receiving of the next value
  }

  // update leds status
  digitalWrite(LED_1_PIN, led_status[0]);
  digitalWrite(LED_2_PIN, led_status[1]);
  digitalWrite(LED_3_PIN, led_status[2]);
}
