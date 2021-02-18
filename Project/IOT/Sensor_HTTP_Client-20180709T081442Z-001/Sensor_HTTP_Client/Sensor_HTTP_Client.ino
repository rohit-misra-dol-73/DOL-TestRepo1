#include <LiquidCrystal.h>                // include the library code:
#include <SimpleDHT.h>

int pinDHT11 = 6;      //DTH11 connected on Pin 12 i.e. B4 in IomaTic
SimpleDHT11 dht11;

LiquidCrystal lcd(11,12,14,15,16,17);  // initialize the library with the numbers of the interface pins

char Input[200];

int tmp=0;
String serialResponse = "";
String arr[22];

    byte temperature = 0;
  byte humidity = 0;


int cnt=0;
int Tick=0;

int8_t answer;
int onModulePin= 2;
char aux_str[129];

float w=0;

int smsdone=0;
int calldone=0;

char PhoneNo[]="+917021237256";

void setup() {
  lcd.begin(16, 4);  

  PowerUpModem();
  
  Serial.begin(9600);
}

void loop() {

delay(1000);
  Tick++;



  
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(pinDHT11, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    //Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }


  lcd.setCursor(0,0);                     // Set LCD cursor at first character of first line.
  lcd.print("Current Temp....");
    lcd.setCursor(0,1);                   //Set cursor at first character/coloumn of first line/row
    lcd.print("Val:");       //Print the message as metioned cursor location

    lcd.print((int)temperature);
    lcd.print(" *C, ");       //Print the message as metioned cursor location

      lcd.print((int)humidity); 
      lcd.print(" H");
      
  if((int)temperature>=31 && smsdone==0)
  {
    lcd.setCursor(0,0);                     // Set LCD cursor at first character of first line.
    lcd.print("Sending SMS        ");
    smsdone=1;
    Serial.begin(9600);                   //Initialize a serial communication with baud rate 9600
    delay(1000);
    Serial.println("AT+CMGF=1");          //Initialize the GSM modem
    delay(2000);
    Serial.print("AT+CMGS=\"");           //Send dial a phone AT command
    Serial.print(PhoneNo);                //Send SMS receiver's phone number
    Serial.write(0x22);                   //Hex code equivalent to "
    Serial.write(0x0D);                   //Hex code equivalent to carraige return i.e. \r
    Serial.write(0x0A);                   //Hex code equivalent to new line char i.e. \n
    delay(2000);
    Serial.print("Please check the temp... :"); //Test SMS Message Body to Send
    Serial.print((int)temperature);
    Serial.print(" Degree.");
    delay(500);
    Serial.println(char(26));             //character to terminate SMS and init sending process i.e. Ctrl+Z
  }

  if((int)temperature>=33 && calldone==0)
  {
    lcd.setCursor(0,0);                     // Set LCD cursor at first character of first line.
    lcd.print("Making Call        ");
    Serial.begin(9600);                   //Initialize a serial communication with baud rate 9600
    delay(1000);
    Serial.println("AT");                 //Initialize the GSM modem
    delay(2000);
    Serial.print("ATD");                  //Send dial a phone AT command
    Serial.print(PhoneNo);              //Send phone number to dial
    Serial.print(";");
    Serial.print("\r\n");
    calldone=1;
    //delay(20000);    
  }

  if (Tick >= 20)
  { 
    lcd.setCursor(0,0);                     // Set LCD cursor at first character of first line.
    lcd.print("Uploading Data        ");
    UploadData(); 
    Tick=0;
  }  
}



void PowerUpModem()
{
    pinMode(13,OUTPUT);              //SIM808 wakeup connected on pin 13 in IomaTic board
    digitalWrite(13, HIGH);          //Initialize the SIM808 Module 
    delay(1000);
    digitalWrite(13, LOW);           //Sending wake up signal to SIM808 Module
    delay(1000);
    digitalWrite(13, HIGH);          //Keeping SIM808 in active/wakeup state
    delay(5000);
}



void UploadData()
{
    //Check the registration status
    while( (sendATcommand("AT+CREG?", "+CREG: 0,1", 500) || 
    sendATcommand("AT+CREG?", "+CREG: 0,5", 500)) == 0 );

     //Enable bearer 1
     sprintf(aux_str, "AT+SAPBR=1,1");
     sendATcommand(aux_str, "OK", 2000);

     //Check whether bearer 1 is open.
     sprintf(aux_str, "AT+SAPBR=2,1");
     sendATcommand(aux_str, "OK", 2000);
     delay(6000);

    //Initialize HTTP service
     sprintf(aux_str, "AT+HTTPINIT");
     sendATcommand(aux_str, "OK", 2000);

    //http://data.iomatic.in/StoreSensorReading.aspx?VAL=2222*35*60*40*40

     Serial.print("AT+HTTPPARA=\"URL\",\"http://data.iomatic.in/StoreSensorReading.aspx?VAL=");
     Serial.print("0700"); Serial.print("*");
     
     if((int)temperature==28)      Serial.print("28");
     if((int)temperature==29)     Serial.print("29");
     if((int)temperature==30)      Serial.print("30");
     if((int)temperature==31)      Serial.print("31");
     if((int)temperature==32)      Serial.print("32");
     if((int)temperature==33)      Serial.print("33");
     if((int)temperature==34)      Serial.print("34");
     if((int)temperature==35)      Serial.print("35");
     if((int)temperature==36)      Serial.print("36");
     if((int)temperature==37)      Serial.print("37");
     if((int)temperature==38)      Serial.print("38");
     if((int)temperature==39)      Serial.print("39");
     if((int)temperature==40)      Serial.print("40");  
     if((int)temperature==41)      Serial.print("41");
     if((int)temperature==42)      Serial.print("42");
     if((int)temperature==43)      Serial.print("43");
     if((int)temperature==44)      Serial.print("44");
     if((int)temperature==45)      Serial.print("45");
     
     Serial.print("*");
     Serial.print("0"); Serial.print("*");
     Serial.print("0"); Serial.print("*");
     Serial.print("0"); Serial.println("\"");

     
     //Set the context ID
     sprintf(aux_str, "AT+HTTPPARA=\"CID\",1");
     sendATcommand(aux_str, "OK", 2000);

     //Set up the HTTP action   
     sprintf(aux_str, "AT+HTTPACTION=0");
     sendATcommand(aux_str, "OK", 2000);


      //Do a HTTP read
     sprintf(aux_str, "AT+HTTPREAD");
     sendATcommand(aux_str, "OK", 2000);


      //Wait for the HTTP response
      delay(6000);

     //Terminate the HTTP service
     sprintf(aux_str, "AT+HTTPTERM");
     sendATcommand(aux_str, "OK", 2000);

}




int8_t sendATcommand(char* ATcommand, char* expected_answer, unsigned int timeout){

  uint8_t x=0,  answer=0;
  char response[100];
  unsigned long previous;

  memset(response, '\0', 100);    // Initialice the string

  delay(100);

  while( Serial.available() > 0) Serial.read();    // Clean the input buffer

  Serial.println(ATcommand);    // Send the AT command 


    x = 0;
  previous = millis();

  // this loop waits for the answer
  do{
    // if there are data in the UART input buffer, reads it and checks for the answer
    if(Serial.available() != 0){    
      response[x] = Serial.read();
      x++;
      // check if the desired answer is in the response of the module
      if (strstr(response, expected_answer) != NULL)    
      {
        //Serial.println(response);
        answer = 1;
      }
    }
    // Waits for the answer with time out
  }
  while((answer == 0) && ((millis() - previous) < timeout));    

  return answer;
}

