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

enum IdBtns {
  POWER = 0x45,
  VOL_UP = 0x46,
  STOP = 0x47,
  BACKWARD = 0x44,
  PLAY = 0x40,
  FORWARD = 0x43,
  ARROW_DOWN = 0x7,
  VOL_DOWN = 0x15,
  ARROW_UP = 0x9,
  ZERO = 0x16,
  EQ = 0x19,
  REPT = 0xD,
  ONE = 0xC,
  TWO = 0x18,
  THREE = 0x5E,
  FOUR = 0x8,
  FIVE = 0x1C,
  SIX = 0x5A,
  SEVEN = 0x42,
  EIGHT = 0x52,
  NINE = 0x4A
};

void setup() {
  // init serial communication
  Serial.begin(115200);
  // init the IR receiver
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
}

void loop() {
  // check data from sensor
  if (IrReceiver.decode()) {
    uint16_t command = IrReceiver.decodedIRData.command;
  
    switch (command) {
      case POWER:
        Serial.println("Pressed POWER button!");
        break;
      case VOL_UP:
        Serial.println("Pressed VOL_UP button!");
        break;
      case STOP:
        Serial.println("Pressed STOP button!");
        break;
      case BACKWARD:
        Serial.println("Pressed BACKWARD button!");
        break;
      case PLAY:
        Serial.println("Pressed PLAY button!");
        break;
      case FORWARD:
        Serial.println("Pressed FORWARD button!");
        break;
      case ARROW_DOWN:
        Serial.println("Pressed ARROW_DOWN button!");
        break;
      case VOL_DOWN:
        Serial.println("Pressed VOL_DOWN button!");
        break;
      case ARROW_UP:
        Serial.println("Pressed ARROW_UP button!");
        break;
      case ZERO:
        Serial.println("Pressed ZERO button!");
        break;
      case EQ:
        Serial.println("Pressed EQ button!");
        break;
      case REPT:
        Serial.println("Pressed REPT button!");
        break;
      case ONE:
        Serial.println("Pressed ONE button!");
        break;
      case TWO:
        Serial.println("Pressed TWO button!");
        break;
      case THREE:
        Serial.println("Pressed THREE button!");
        break;
      case FOUR:
        Serial.println("Pressed FOUR button!");
        break;
      case FIVE:
        Serial.println("Pressed FIVE button!");
        break;
      case SIX:
        Serial.println("Pressed SIX button!");
        break;
      case SEVEN:
        Serial.println("Pressed SEVEN button!");
        break;
      case EIGHT:
        Serial.println("Pressed EIGHT button!");
        break;
      case NINE:
        Serial.println("Pressed NINE button!");
        break;
      default:
        Serial.println("Invalid data!");
    }

    IrReceiver.resume(); // enable receiving of the next value
  }

}
