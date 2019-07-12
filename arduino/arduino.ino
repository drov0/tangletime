/*
    IR remote keypad
   0 : FF6897
   1 : FF18E7
   2 : FF6897
   3 : FF7A85
   4 : FF10EF
   5 : FF38C7
   6 : FF5AA5

*/

#include <IRremote.h>
#include <SoftwareSerial.h>
SoftwareSerial EEBlue(10, 11); // RX | TX


int RECV_PIN = 12;        // Infrared receiving pin
IRrecv irrecv(RECV_PIN); // Create a class object used to receive class
decode_results results; // Create a decoding results class object

void setup()
{
  Serial.begin(9600); // Initialize the serial port and set the baud rate to 9600
  Serial.println("UNO is ready!");  // Print the string "UNO is ready!"
  irrecv.enableIRIn(); // Start the receiver
  EEBlue.begin(9600);
}

char value_to_char(unsigned long val)
{
  if (val == 16738455)
    return '0';
  else if (val == 16724175)
    return '1';
  else if (val == 16718055)
    return '2';
  else if (val == 16743045)
    return '3';
  else if (val == 16716015)
    return '4';
  else if (val == 16726215)
    return '5';
  else if (val == 16734885)
    return '6';
  else if (val == 4294967295)
    return 'X';
  else 
    return '?';
  

}

void loop() {

  if (irrecv.decode(&results)) {
    // Waiting for decoding
    Serial.println(results.value); // Print out the decoded results
    Serial.println(value_to_char(results.value)); // Print out the decoded results



    EEBlue.write(value_to_char(results.value));

    irrecv.resume(); // Receive the next value
  }

  // Feed any data from bluetooth to Terminal.
  if (EEBlue.available())
  {
    Serial.println(EEBlue.read());
    Serial.println("yesy");

  }

  // Feed all data from termial to bluetooth
  if (Serial.available())
    EEBlue.write(Serial.read());

  delay(100);

}
