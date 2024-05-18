/**
 * The LCD can be seen as a matrix, so the text is organized in rows and columns.
 *
 * The Cursor allow us to write text in different places of that matrix.
 * To set the postion to write the charactor (or entire string) we have to use 
 * setCursor(uint8_t, uint8_t). The first argument is the columns' index and 
 * the second argument is the rows' index.
 *
 * TIP: the cursor is a moving pointer, so when we write something the cursor will be
 * moved in the location next to the last char written!
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
  lcd.begin(LCD_WIDTH, LCD_HEIGHT);

  // lcd.setCursor(0, 0); // The text will show in top-left corner! - it is the default position
  lcd.setCursor(0, 0);
  lcd.print("Hello");
  lcd.setCursor(5, 1);
  lcd.print("World");
  lcd.print("!"); // note that the '!' char is written into next cursor position after execuring line 43

  delay(3000); // [ms]
  lcd.clear(); // clear the entire screen
}

void loop() {

}
