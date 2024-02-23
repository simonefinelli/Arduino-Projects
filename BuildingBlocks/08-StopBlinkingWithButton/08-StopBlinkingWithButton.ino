/*
 * This program makes LEDs blinking only if the button is not pressed.
 * When the button is pressed the LEDs have to stay in their actual status,
 * on or off.
 */

#define LED1_PIN 2 
#define LED2_PIN 3
#define LED3_PIN 4
#define PUSHBTN_PIN 13

int step = 1;
byte volt1 = 0;  // byte range 0-255
byte volt2 = 0;

void setup() {
  Serial.begin(9600);  // init logger
  
  // leds
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  
  // button
  pinMode(PUSHBTN_PIN, INPUT);
}

void loop() {
  if (!digitalRead(PUSHBTN_PIN)) {
    Serial.println("Button NOT pressed!");
    if (step == 1) {
      volt1 = LOW;
      volt2 = HIGH;
      step = 2;
    } else {
      volt1 = HIGH;
      volt2 = LOW;
      step = 1;
    }  

    digitalWrite(LED1_PIN, volt1);
    digitalWrite(LED2_PIN, volt2);
    digitalWrite(LED3_PIN, volt1);
    delay(400);
  }
}