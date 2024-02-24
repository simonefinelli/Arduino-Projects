/**
 * Serial is used for communication between the Arduino board 
 * and a computer or other devices. All Arduino boards have at
 * least one serial port (also known as a UART or USART), 
 * and some have several.
 *
 * For example, Arduino UNO R3 uses serial pins 0(RX),1(TX) to receive and transmit data.
 *
 * To send data from Arduino to Serial Monitor (PC log) we can use Serial.println.
 * 
 * More on: https://www.arduino.cc/reference/en/language/functions/communication/serial/
 */

void setup() {
  Serial.begin(9600); // open the serial port to receive/send at
                      // 9600 baud-rate (bps)
  Serial.println("Communication Initialized");  // log on serial communication
  pinMode(LED_BUILTIN, OUTPUT);
  
}

void loop() {
  Serial.println("Built-in Led ON");
  digitalWrite(LED_BUILTIN, HIGH);
  delay(2000); // Wait for 1000 millisecond(s)
  
  Serial.println("Built-in Led OFF");
  digitalWrite(LED_BUILTIN, LOW);
  delay(2000); // Wait for 1000 millisecond(s)
}