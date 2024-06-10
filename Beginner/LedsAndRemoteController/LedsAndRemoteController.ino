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
#include <LiquidCrystal.h>

/// LEDs config
#define LED_1_PIN 10
#define LED_2_PIN 11 
#define LED_3_PIN 12
unsigned led_status[3] = {0};  // handle on-off of leds

/// IR remote controller config
#define IR_RECEIVE_PIN 5
enum IdBtns {
  STOP = 0x47,
  ZERO = 0x16,
  ONE = 0xC,
  TWO = 0x18,
  THREE = 0x5E
};

/// LCD config
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

char formatted_str[17];  // formatted string to show distance on lcd

void setup() {
  // init serial communication
  Serial.begin(115200);
  // init the IR receiver
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  // init leds
  pinMode(LED_1_PIN, OUTPUT);
  pinMode(LED_2_PIN, OUTPUT);
  pinMode(LED_3_PIN, OUTPUT);
  // init LCD
  lcd.begin(LCD_WIDTH, LCD_HEIGHT);
  lcd.setCursor(0, 0);
}

void loop() {
  // check data from sensor
  if (IrReceiver.decode()) {
    uint16_t command = IrReceiver.decodedIRData.command;
  
    switch (command) {
      case STOP:
        Serial.println("Pressed button STOP!");
        memset(formatted_str, ' ', 17);
        break;
      case ZERO:
        Serial.println("Pressed button ZERO!");
        led_status[0] = LOW;
        led_status[1] = LOW;
        led_status[2] = LOW;
        sprintf(formatted_str, "Turnoff all LEDs");
        break;
      case ONE:
        Serial.println("Pressed button ONE!");
        led_status[0] = led_status[0] == HIGH ? LOW : HIGH;
        sprintf(formatted_str, "Toggle LED 1!");
        break;
      case TWO:
        Serial.println("Pressed button TWO!");
        led_status[1] = led_status[1] == HIGH ? LOW : HIGH;
        sprintf(formatted_str, "Toggle LED 2!");
        break;
      case THREE:
        Serial.println("Pressed button THREE!");
        led_status[2] = led_status[2] == HIGH ? LOW : HIGH;
        sprintf(formatted_str, "Toggle LED 3!");
        break;
      default:
        Serial.println("Invalid data!");
    }
    // enable receiving of the next value
    IrReceiver.resume();
    // update lcd
    lcd.print(formatted_str);
    lcd.setCursor(0, 0);
  }

  // update leds status
  digitalWrite(LED_1_PIN, led_status[0]);
  digitalWrite(LED_2_PIN, led_status[1]);
  digitalWrite(LED_3_PIN, led_status[2]);
}
