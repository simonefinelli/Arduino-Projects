/**
 * EEPROM stands for Electrically Erasable Programmable Read-Only Memory.
 * It is a type of non-volatile memory that can be electrically erased and reprogrammed.
 * Unlike EPROM (Erasable Programmable Read-Only Memory),
 * EEPROM does not require exposure to ultraviolet light to erase its contents.
 * 
 * Key characteristics and features of EEPROM:
 * - Non-volatile: EEPROM retains its data even when the power is turned off,
 *     making it suitable for storing data that needs to be retained even when the device is not powered.
 * - Electrically Erasable: Unlike some other types of memory, EEPROM can be erased and reprogrammed electrically 
 *     without the need for special equipment.
 * - Programmable: Data can be written to and read from EEPROM using electrical signals.
 * - Limited Endurance: EEPROM has a limited number of write and erase cycles per address (single byte), 
 *     typically around 100,000 to 1 million cycles, depending on the specific technology and manufacturer.
 * - Limited Storage: for example in Arduino Uno boards the maximum storage is 1024 bytes.
 *
 * Due these limitations, is good approach use it only for small values and only for values that 
 * we do not update too often (like default settings).
 * 
 * ATTENTION: due read/write cycle limitation do NOT write/read in EEPROM at full speed in the fast loops (like loop()).
 */

#include <EEPROM.h>

void setup() {
  Serial.begin(115200);

  // store some values onto EEPROM memory - use only once to avoid unnecessary writing!
  // EEPROM.write(0, 42);  // first param is the address (0-1023), second param is the value (0-255)
  // EEPROM.write(1023, 255);

  // read from EEPROM memory
  Serial.println(EEPROM.read(0));
  Serial.println(EEPROM.read(200));  // garbage
  Serial.println(EEPROM.read(1023));
}

void loop() {
  // put your main code here, to run repeatedly:

}
