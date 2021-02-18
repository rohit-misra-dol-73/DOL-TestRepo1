/*
  IomaTic Liquid Crystal Display Sample  - 

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 The circuit:
 * LCD RS pin to digital pin 14 i.e. A0
 * LCD Enable pin to digital pin 15 i.e A1
 * LCD D4 pin to digital pin 8
 * LCD D5 pin to digital pin 9
 * LCD D6 pin to digital pin 10
 * LCD D7 pin to digital pin 11

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalDisplay

 */

// NOTE: Please check the DIP switches configuration before uploading the code

#include <LiquidCrystal.h>                // include the library code:

LiquidCrystal lcd(11,12,14,15,16,17);  // initialize the library with the numbers of the interface pins

void setup() 
{
  lcd.begin(16, 4);                       // set up the LCD's number of columns and rows:

  Serial.begin(9600);
}

void loop() 
{

  if(Serial.available())
  {
    lcd.write(Serial.read());
  }
 }
