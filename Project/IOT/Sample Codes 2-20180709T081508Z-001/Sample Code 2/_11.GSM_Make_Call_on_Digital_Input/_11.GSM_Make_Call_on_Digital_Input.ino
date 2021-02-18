
#include <LiquidCrystal.h>                // include the library code:

LiquidCrystal lcd(14, 15, 8, 9, 10, 11);  // initialize the library with the numbers of the interface pins

char PhoneNo[]="+919579024407";
int DialStatus=0;

// variables will change:
int buttonState = 0; 

const int buttonPin = 2;     // the number of the pushbutton pin

void setup() 
{
    pinMode(buttonPin,INPUT_PULLUP);
    
    pinMode(13,OUTPUT);              //SIM808 wakeup connected on pin 13 in IomaTic board
    digitalWrite(13, HIGH);          //Initialize the SIM808 Module 
    delay(1000);
    digitalWrite(13, LOW);           //Sending wake up signal to SIM808 Module
    delay(1000);
    digitalWrite(13, HIGH);          //Keeping SIM808 in active/wakeup state
    delay(10000);
  
    lcd.begin(16, 2);                     //Initialize the LCD in 16x2 mode
    delay(1000);            
    lcd.setCursor(0,0);                   //Set cursor at first character/coloumn of first line/row
    lcd.print("     IomaTic        ");    //Print the message as metioned cursor location

    lcd.setCursor(0,1);                   //Set cursor at first character/coloumn of first line/row
    lcd.print("GSM Dial on Input....");     //Print the message as metioned cursor location

    Serial.begin(9600);                   //Initialize a serial communication with baud rate 9600
    delay(1000);
    
}

void loop() 
{   
    //This is single task program hence nothing to do in loop,
    //everything will be executed in setup function only.

    // read the state of the pushbutton value:
    buttonState = digitalRead(buttonPin);

    if(buttonState==LOW)
    {
       lcd.setCursor(0,1);                   //Set cursor at first character/coloumn of first line/row
       lcd.print("Input State=HIGH   ....");     //Print the message as metioned cursor location

        if(DialStatus==0)
        {
          Serial.println("AT");                 //Initialize the GSM modem
          delay(2000);
          Serial.print("ATD");                  //Send dial a phone AT command
          Serial.print(PhoneNo);              //Send phone number to dial
          Serial.print(";");
          Serial.print("\r\n");

          DialStatus=1;
        }  
       
    }
    else
    {
       lcd.setCursor(0,1);                   //Set cursor at first character/coloumn of first line/row
       lcd.print("Input State=LOW   ....");     //Print the message as metioned cursor location  

       DialStatus=0;
    }
}
