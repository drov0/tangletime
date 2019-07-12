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
/*
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

  void loop() {
  /*EEBlue.write('R');
  if (irrecv.decode(&results)) {
    // Waiting for decoding
    Serial.println(results.value, HEX); // Print out the decoded results
    EEBlue.write('R');
    EEBlue.write('\n');
    EEBlue.write(results.value);

    irrecv.resume(); // Receive the next value
  }

  // Feed any data from bluetooth to Terminal.
  if (EEBlue.available())
  {
    Serial.println(EEBlue.read());
    Serial.println("yesy");

  }
  /*
  // Feed all data from termial to bluetooth
  if (Serial.available())
    EEBlue.write(Serial.read());

  delay(100);

  }
*/
#include <SoftwareSerial.h>
SoftwareSerial EEBlue(10, 11); // RX | TX
void setup()
{

  Serial.begin(9600);
  EEBlue.begin(9600);  //Default Baud for comm, it may be different for your Module.
  Serial.println("The bluetooth gates are open.\n Connect to HC-05 from any other bluetooth device with 1234 as pairing key!.");

}

void loop()
{

  // Feed any data from bluetooth to Terminal.
  if (EEBlue.available())
    Serial.write(EEBlue.read());

  // Feed all data from termial to bluetooth
  if (Serial.available())
    EEBlue.write(Serial.read());
}
