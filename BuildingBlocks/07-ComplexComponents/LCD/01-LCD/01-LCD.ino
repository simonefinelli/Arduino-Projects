/**
 * In this lecture we will explore the LCD actuator (we do not call it as sensor
 * because we can control its behaviour from Arduino).
 *
 * The LCD is an easy-to-use component. It can use to print at screen all sort of text.
 *
 * The LCD has several pins:
 *  - VSS (Ground): Connected to GND.
 *  - VDD (Power): Connected to +5V.
 *  - VO (Contrast): Connected usually to a potentiometer to adjust screen contrast.
 *  - RS (Register Select): Connected to a digital pin. In this case we use an anolog pin (no other digital pin free).
 *  - RW (Read/Write): Connected to ground if you're only writing to the LCD.
 *  - E (Enable): Connected to a digital pin. In this case we use an analog pin (no other digital pin free).
 *  - D4-D7 (Data Pins): Connected to digital pins.
 *  - A (Backlight Anode): Connected to +5V or a PWM pin if you want to control backlight brightness.
 *  - K (Backlight Cathode): Connected to GND.
 */

#include <LiquidCrystal.h>  // library to handle LCD functionalities

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

void setup() {
  lcd.begin(LCD_WIDTH, LCD_HEIGHT);  // the LCD is a matrix!

  lcd.print("Hello World");
}

void loop() {

}
