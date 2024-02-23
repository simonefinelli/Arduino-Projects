/*
 * Uses a Push Button (Input) to trigger a LED (Outpu).
 */
#define LED_PIN 12
#define PUSHBTN_PIN 2

void setup()
{
  Serial.begin(9600);  // init logger
  
  pinMode(LED_PIN, OUTPUT);  // set mode of the LED
  pinMode(PUSHBTN_PIN, INPUT);  // set mode of the button
}

void loop()
{
  int btn_state = digitalRead(PUSHBTN_PIN);
  Serial.println("The state of the Button is " + String(btn_state));
  // TIP: LOW and HIGH values are mapped with 0 and 1 respectively.
  
  if (btn_state) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
  
  delay(100);  // 10Hz
}