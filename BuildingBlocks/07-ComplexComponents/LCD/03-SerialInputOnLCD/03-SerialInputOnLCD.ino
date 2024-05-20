/*
 * In this program we can use the Serial communication to get the 
 * user input and display it on the LCD.
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

/// concurrency
unsigned delay_rate = 500; // [ms]
unsigned long prev_t = millis();
unsigned long curr_t = 0;

/// text buffer
String buffer[2]{};

String user_txt = "";
uint8_t toggle_line = 0;

void setup() {
  // init serial communication
  Serial.begin(115200);
  Serial.setTimeout(10); // buffer time [ms]

  // init LCD
  lcd.begin(LCD_WIDTH, LCD_HEIGHT);
  lcd.setCursor(0, 0);
}

void loop() {
  curr_t = millis();

  // get user input
  if (Serial.available() > 0) {
    user_txt = Serial.readString();
    if (user_txt.length() < 16) {
      if (buffer[0].length() == 0) {
        add_pading(user_txt);
        buffer[0] = user_txt;
      } else if (buffer[1].length() == 0) {
        add_pading(user_txt);
        buffer[1] = user_txt;
      } else {
        // put second text on first location in buffer
        // and write new string in second location
        buffer[0] = buffer[1];
        add_pading(user_txt);
        buffer[1] = user_txt;
      }
    } else {
      Serial.println("Error: Text too long!");
    }
  }

  // show text on LCD
  if ((curr_t - prev_t) > delay_rate) {
    // update text on LCD
    lcd.setCursor(0, 0); 
    lcd.print(buffer[0]);
    lcd.setCursor(0, 1);
    lcd.print(buffer[1]);
    prev_t += delay_rate;
  }
}

/*
 * The function add padding to the text in order to overwrite other previous chars.
 * That is useful to avoid to use clear() funtion (the refresh rate is high 
 * so we could see LCD blinking).
 */
void add_pading(String& s) {
   for(size_t i = s.length(); i < LCD_WIDTH; i++) {
    s += " ";
   }
}