/*
 * Trim a led brightness with a Potentiometer.
 */
#define LED_PIN_1 11
#define LED_PIN_2 2
#define PUSHBTN_PIN 3
#define POTENTIOMETER_PIN A2

void setup()
{
  Serial.begin(9600);  // init logger
  
  pinMode(LED_PIN_1, OUTPUT);  // analog mode
  pinMode(LED_PIN_2, OUTPUT);
  pinMode(PUSHBTN_PIN, INPUT); 
  // REMEMBER: Analog IN pin must not be initialize with pinMode()
}

void loop()
{ 
  // Push Button
  if (digitalRead(PUSHBTN_PIN)) {
    digitalWrite(LED_PIN_2, HIGH);
  } else {
    digitalWrite(LED_PIN_2, LOW);
  }
  
  // Potentimeter
  Serial.print("Potentiometer: ");
  Serial.println(analogRead(POTENTIOMETER_PIN));
  // transfor potentiometer's values to LED range values
  int led_brightness = int(analogRead(POTENTIOMETER_PIN) * 0.25);
  Serial.print("LED: ");
  Serial.println(led_brightness);
  analogWrite(LED_PIN_1, led_brightness);  // 100 to 0% of 5v
  
  
  delay(100);  // 10Hz
}