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
