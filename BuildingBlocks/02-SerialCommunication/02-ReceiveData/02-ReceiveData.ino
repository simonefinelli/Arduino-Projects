/**
 * Serial is used for communication between the Arduino board 
 * and a computer or other devices. All Arduino boards have at
 * least one serial port (also known as a UART or USART), 
 * and some have several.
 *
 * For example, Arduino UNO R3 uses serial pins 0(RX),1(TX) to receive and transmit data.
 *
 * To receive data from "outside" to Arduino we can use Serial.println.
 * 
 * More on: https://www.arduino.cc/reference/en/language/functions/communication/serial/
 */

long tmp1 = 0;
double tmp2 = 0;
String tmp3{};

void setup() {
  Serial.begin(115200); // open the serial port to receive/send at default
                      // 9600 baud-rate (bps) - 115200bps is the most commont value (great trade-off between velocity and data loss (0.0001% chance of loss))
  Serial.setTimeout(10); // [ms] - set the ti e that the serial communication use to listen to data, default is 1000ms
  Serial.println("Communication Initialized");  // log on serial communication
}

void loop() {
  // Serial.available() gets the number of bytes (characters) available for reading from the serial port.
  // This is data that’s already arrived and stored in the serial receive buffer (which holds 64 bytes).
  if (Serial.available() > 0){  // check if we have bytes to read
    // tmp1 = Serial.parseInt();  // read integer
    // tmp2 = Serial.parseDouble();  // read double
    tmp3 = Serial.readString();  // read string
    Serial.println(tmp3);
  }
}
