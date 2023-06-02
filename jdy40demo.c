/*  Wireless Communication using  jdy40 Transmitter Example 
Sequence Function Parameter instructions
1 Baud rate 9600 ------->AT+BAUD  //9600 default
2 Wireless ID 8899 ------->AT+RFID8899(4000-8899) we can talk to multiple jdy40 by changing transmitters rfid 
to the recievers id
3 Device ID 1122 ------->AT+DVID1122
4 Channel 001 ------->AT+RFC001 (001-128) channel updates only when power is removed
5 Transmit power 12db ------->AT+POWE9
6 Device type A0-------> AT+CLSSA0
both TX and RX device should have same DVID(device id) and RFID(radio frequency id) To work
*/

#include <SoftwareSerial.h>
#define setPin 6
SoftwareSerial jdy40(10, 11); // jdy40 TX Pin, jdy40 RX Pin

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
	/*allways add the \r\n when sending data*/
  jdy40.print("Hello Flex\r\n");      // Send that data to jdy40
   //jdy40.println("sending some data");  //you can use jdy40.println it adds \r\n
   delay(300);
  }
}



/* Wireless Communication using jdy40 Example Reciever
 Sequence Function Parameter instructions
1 Baud rate 9600 ------->AT+BAUD  //9600 default
2 Wireless ID 8899 ------->AT+RFID8899(4000-8899)
3 Device ID 1122 ------->AT+DVID1122
4 Channel 001 ------->AT+RFC001 (001-128)
5 Transmit power 12db ------->AT+POWE9
6 Device type A0-------> AT+CLSSA0
both TX and RX device should have same DVID and RFID To work
*/



#include <SoftwareSerial.h>
#define setPin 6
SoftwareSerial jdy40(10, 11); // jdy40 TX Pin, jdy40 RX Pin
byte incomingByte;
String readBuffer = "";


void setup() {
  Serial.begin(9600);             // Serial port to computer
  jdy40.begin(9600);               // Serial port to jdy40
   pinMode(setPin, OUTPUT);
  digitalWrite(setPin, HIGH);     // jdy40 normal mode
  //digitalWrite(setPin, LOW);     // jdy40 AT mode
}

void loop() {

for(;;){
  //handle data coming to jdy40
    while (jdy40.available()) {        // If jdy40 has data
    Serial.write(jdy40.read());      // Send the data to Serial monitor
  }
  
   //handle data coming to serial monitor
  while (Serial.available()) {      // If Serial monitor has data
    jdy40.write(Serial.read());      // Send that data to jdy40
  } 
  
}}



/**********Wireless Lcd Transmitter*************/
/*Sequence Function Parameter instructions
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
                             "Text on a 16x2 lcd thats cool      \r\n",
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


/**********Wireless Lcd Reciever*************/
#include <SoftwareSerial.h>
#define setPin 6
#include <PCF8574_HD44780_I2C.h>

PCF8574_HD44780_I2C lcd(0x27,16,2);
SoftwareSerial jdy40(10, 11); // jdy40 TX Pin, jdy40 RX Pin
byte incomingByte;
String readBuffer = "";
char mydata[33];


void setup() {
  Serial.begin(9600);             // Serial port to computer
  jdy40.begin(9600);               // Serial port to jdy40
   lcd.init();  //initialuse the lcd
  lcd.backlight();          // Backlight ON
   pinMode(setPin, OUTPUT);
  digitalWrite(setPin, HIGH);     // jdy40 normal transparent mode
 lcd.print("JDY-40 Test"); 
delay(2000);
   //digitalWrite(setPin, LOW);     //Set AT Command Mode
    //jdy40.print("AT+RFC004\r\n"); // Send the AT Command to the other module
   // delay(200);
    //digitalWrite(setPin, HIGH);     // jdy40 normal mode
}

void loop() {
 for(;;){

  if(jdy40.available()) // if we have data
  {
     lcd.clear();  //clear lcd
     delay(100);
     int j=0;
   
    while(jdy40.available()){
     mydata[j++]=jdy40.read();
     //Serial.write(jdy40.read());      // Send the data to Serial monitor
    }

    for(;j<33;j++){  //clears the rest
      mydata[j++]=' ';
    }

   for(j=0;j<16;j++){  //prints the first row
      lcd.print(mydata[j]); 
    }
    
    //prints the second row
    lcd.setCursor(0, 1);
    for(j=16;j<33;j++){ 
     lcd.print(mydata[j]);
    } 
    delay(2000);
    }  
  } 
}


/**********Wireless Servo Reciever*************/
#include <SoftwareSerial.h>
#define setPin 6
#include <PCF8574_HD44780_I2C.h>
#include <Servo.h>

PCF8574_HD44780_I2C lcd(0x27,16,2);
SoftwareSerial jdy40(10, 11); // jdy40 TX Pin, jdy40 RX Pin
byte incomingByte;
String readBuffer = "";
char mydata[33];
Servo myServo;
 int j=0;
 
 
void setup() {
  Serial.begin(9600);             // Serial port to computer
  jdy40.begin(9600);               // Serial port to jdy40
   lcd.init();  //initialuse the lcd
  lcd.backlight();          // Backlight ON
  myServo.attach(9);
   pinMode(setPin, OUTPUT);
  digitalWrite(setPin, HIGH);     // jdy40 normal transparent mode
  lcd.print("JDY-40 Servo Control"); 
delay(2000);

}

void loop() {

  //handle data coming to jdy40
    while (jdy40.available()) {        // If jdy40 has data
	  int val = jdy40.parseInt();    //convert serial data to integer
      mydata[j++]=jdy40.read();
	  myServo.write(val);  //send to servo
	 //Serial.println(val);	  
     delay(5);   
  } 
  
     lcd.clear();  //clear lcd
     delay(100);
      
    for(;j<33;j++){  //clears the rest
      mydata[j++]=' ';
    }

   for(j=0;j<16;j++){  //prints the first row
      lcd.print(mydata[j]); 
    }
    
    //prints the second row
    lcd.setCursor(0, 1);
    for(j=16;j<33;j++){ 
     lcd.print(mydata[j]);
    } 
    //delay(200);
}




/**********Wireless Servo Transmitter*************/
#include <Servo.h>
#include <SoftwareSerial.h>
  
 #define setPin 6
SoftwareSerial jdy40(10, 11); // jdy40 TX Pin, jdy40 RX Pin


const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
  Serial.begin(9600);
  jdy40.begin(9600);               // Serial port to jdy40
   pinMode(setPin, OUTPUT);
  digitalWrite(setPin, HIGH);     // jdy40 normal mode
  //digitalWrite(setPin, LOW);     // jdy40 AT mode

}

void loop() {
	  // read the analog in value:
  sensorValue = analogRead(analogInPin);
 
 // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 180);
  
  jdy40.print(outputValue);      // Send the data to jdy40
  delay(5);

}
   