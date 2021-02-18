
#include <LiquidCrystal.h>                // include the library code:

LiquidCrystal lcd(14, 15, 8, 9, 10, 11);  // initialize the library with the numbers of the interface pins

void setup() 
{
    pinMode(4,OUTPUT);                    //Set pin number 4 as digital out where relay 1 is connected
    pinMode(5,OUTPUT);                    //Set pin number 5 as digital out where relay 2 is connected
    pinMode(6,OUTPUT);                    //Set pin number 6 as digital out where relay 3 is connected

    pinMode(7,OUTPUT);                    //Set pin number 7 as digital out where buzzer is connected

    lcd.begin(16, 2);                     //Initialize the LCD in 16x2 mode
    delay(1000);            
    lcd.setCursor(0,0);                   //Set cursor at first character/coloumn of first line/row
    lcd.print("     IomaTic        ");    //Print the message as metioned cursor location
}

void loop() 
{   
    //In below sequence first set the cusrsor at specifil location to show message on LCD 
    //then write logic HIGH/LOW to ON/OFF the device connected on metioned IO pin

    //------------------Device ON sequence
    
    lcd.setCursor(3,1);     
    lcd.print("RELAY 1 ON ");
    digitalWrite(4, HIGH);                //Write digital HIGH on pin 4 i.e. generating 5v at pin 4 where relay 1 is connected
    delay(1000);

    lcd.setCursor(3,1);  
    lcd.print("RELAY 2 ON ");
    digitalWrite(5, HIGH);                //Write digital HIGH on pin 5 i.e. generating 5v at pin 5 where relay 2 is connected 
    delay(1000);

    lcd.setCursor(3,1);  
    lcd.print("RELAY 3 ON ");
    digitalWrite(6, HIGH);                //Write digital HIGH on pin 6 i.e. generating 5v at pin 6 where relay 3 is connected
    delay(1000);

    lcd.setCursor(3,1);                   
    lcd.print("BUZZER  ON ");
    digitalWrite(7, HIGH);                //Write digital HIGH on pin 7 i.e. generating 5v at pin 4 where buzzer is connected
    delay(1000);
    
    //------------------Device OFF sequence

    lcd.setCursor(3,1);  
    lcd.print("BUZZER  OFF");
    digitalWrite(7, LOW);                 //Write digital LOW on pin 7 i.e. generating 0v at pin 7 where buzzer is connected
    delay(1000);

    lcd.setCursor(3,1);  
    lcd.print("RELAY 3 OFF");
    digitalWrite(6, LOW); 
    delay(1000);

    lcd.setCursor(3,1);  
    lcd.print("RELAY 2 OFF");
    digitalWrite(5, LOW); 
    delay(1000);
    
    lcd.setCursor(3,1);  
    lcd.print("RELAY 1 OFF   ");
    digitalWrite(4, LOW); 
    delay(1000);
}
