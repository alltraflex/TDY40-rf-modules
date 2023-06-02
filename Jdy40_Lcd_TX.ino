/*    Arduino Long Range Wireless Communication using jdy40 Example 01
Sequence Function Parameter instructions
1 Baud rate 9600 ------->AT+BAUD  //9600 default
2 Wireless ID 8899 ------->AT+RFID8899
3 Device ID 1122 ------->AT+DVID1122
4 Channel 001 ------->AT+RFC001 (001-128)
5 Transmit power 12db ------->AT+POWE9
6 Device type A0-------> AT+CLSSA0
*/

#include <SoftwareSerial.h>
#define setPin 6
SoftwareSerial jdy40(10, 11); // jdy40 TX Pin, jdy40 RX Pin

String myStrings[]={"Hello flexo Da best programmer  \r\n",
                              "Jdy40 sending data wirelessly   \r\n",
                             "Text on a 16x2 lcd cool man      \r\n",
                              "The module is very cheap            \r\n",
                              "You can send data Wirelessly    \r\n",
                              "It has a range of 120m                \r\n"};

void setup() {
  Serial.begin(9600);             // Serial port to computer
  jdy40.begin(9600);               // Serial port to jdy40
   pinMode(setPin, OUTPUT);
  digitalWrite(setPin, HIGH);     // jdy40 normal transparent mode
   
   //digitalWrite(setPin, LOW);     //Set AT Command Mode
    //jdy40.print("AT+RFC004\r\n"); // Send the AT Command to the other module
   // delay(200);
    //digitalWrite(setPin, HIGH);     // jdy40 normal mode
}

void loop() {
 
   for (int i=0 ; i<6; i++){
    jdy40.print(myStrings[i]);      // Send that data to jdy40
   delay(3000);
    }
  }
