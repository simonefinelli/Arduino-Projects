/**
 * The program show the usage of a IR (Infrared) Remote System.
 * The system is composed by:
 *  - An IR receiver module
 *  - An IR remote control
 * 
 * The IR reciver has 3 pins:
 *  - G: ground 
 *  - R: power (5v)
 *  - Y: data (connected to a digital pin)
 */

#include <IRremote.hpp>  // this libray has to be installed (ver.: 4.3.1 by shirriff, z3t0, ArminJo)

#define IR_RECEIVE_PIN 5

void setup() {
  // init serial communication
  Serial.begin(115200);
  // init the IR receiver
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
}

void loop() {
  // check data from sensor
  if (IrReceiver.decode()) {
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX); // print "old" raw data
    IrReceiver.printIRResultShort(&Serial); // print complete received data in one line
    IrReceiver.printIRSendUsage(&Serial);   // print the statement required to send this data
    IrReceiver.resume(); // enable receiving of the next value
  }

}
