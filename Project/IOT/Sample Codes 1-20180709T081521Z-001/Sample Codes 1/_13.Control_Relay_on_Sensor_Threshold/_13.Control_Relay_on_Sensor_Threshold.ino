
#include <LiquidCrystal.h>                // include the library code:
#include <SimpleDHT.h>

int pinDHT11 = 6;      //DTH11 connected on Pin 12 i.e. B4 in IomaTic
SimpleDHT11 dht11;

LiquidCrystal lcd(11,12,14,15,16,17);  // initialize the library with the numbers of the interface pins

int sendStatus=0;

void setup() 
{
    pinMode(7,OUTPUT);                   //SIM808 wakeup connected on pin 13 in IomaTic board
    
    lcd.begin(16, 4);                     //Initialize the LCD in 16x2 mode
    delay(1000);            
    lcd.setCursor(0,0);                   //Set cursor at first character/coloumn of first line/row
    lcd.print("     IomaTic        ");    //Print the message as metioned cursor location

    Serial.begin(9600);                   //Initialize a serial communication with baud rate 9600
    delay(1000);
}

void loop() 
{   
 
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(pinDHT11, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess) 
  {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }
  
    lcd.setCursor(0,2);                   //Set cursor at first character/coloumn of first line/row
    lcd.print("Val:");       //Print the message as metioned cursor location

    lcd.print((int)temperature);
    lcd.print(" *C, ");       //Print the message as metioned cursor location

      lcd.print((int)humidity); 
      lcd.print(" H");
      
    delay(500);

    if ((int)humidity && temperature>=30)
    {
      digitalWrite(8,HIGH);
      digitalWrite(9,HIGH);
      digitalWrite(10,HIGH);
    }
    else
    {
      
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW);
    }
    
}
