#include <SoftwareSerial.h>
 
#define DEBUG true
 
SoftwareSerial esp8266(2,3); // make RX Arduino line is pin 2, make TX Arduino line is pin 3.
                             // This means that you need to connect the TX line from the esp to the Arduino's pin 2
                             // and the RX line from the esp to the Arduino's pin 3




void setup()
{
  
  
  Serial.begin(115200);
  esp8266.begin(115200); // your esp's baud rate might be different
  
  pinMode(11,OUTPUT);
  digitalWrite(11,LOW);
  
  pinMode(12,OUTPUT);
  digitalWrite(12,LOW);
  
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
   
  sendData("AT+RST\r\n",10000,DEBUG); // reset module
  //Serial.println("AT+RST\r\n");
    
  //delay(10000);
  
  
  //sendData("AT+CWMODE=3\r\n",10000,DEBUG); // configure as access point
  //Serial.println("AT+CWMODE=2\r\n");

  
  
  //delay(3000);
  sendData("AT+CIFSR\r\n",10000,DEBUG); // get ip address
  //Serial.println("AT+CIFSR\r\n");
  
  
  //delay(3000);
  sendData("AT+CIPMUX=1\r\n",10000,DEBUG); // configure for multiple connections
  //Serial.println("AT+CIPMUX=1\r\n");
  
  
  //delay(3000);
  sendData("AT+CIPSERVER=1,80\r\n",10000,DEBUG); // turn on server on port 80
  //Serial.println("AT+CIPSERVER=1,80\r\n");

  delay(1000);
}
 
void loop()
{


  //sendData("AT+RST\r\n",2000,DEBUG); // reset module
  //delay(1000);
  //delay(1000);
  
  if(esp8266.available()) // check if the esp is sending a message 
  {
 
    //Serial.println("123123");
    
      
     
          
     if(esp8266.find("+IPD,"))    // advance cursor to "pin="
     {

       delay(1000);
       
       int connectionId = esp8266.read()-48;

       esp8266.find("pin=");


     
     int pinNumber = (esp8266.read()-48)*10; // get first number i.e. if the pin 13 then the 1st number is 1, then multiply to get 10
     pinNumber += (esp8266.read()-48); // get second number, i.e. if the pin number is 13 then the 2nd number is 3, then add to the first number


     if(pinNumber==13) digitalWrite(13, HIGH);
     else if(pinNumber==12) digitalWrite(13, LOW);

     if(pinNumber==11) digitalWrite(12, HIGH);
     else if(pinNumber==10) digitalWrite(12, LOW);

     
     
     
     //digitalWrite(13, HIGH);
     //delay(1000);

     //digitalWrite(13, LOW);
     //delay(1000);
     
     

     
     // make close command
     String closeCommand = "AT+CIPCLOSE="; 
     closeCommand+=connectionId; // append connection id
     closeCommand+="\r\n";
     
     sendData(closeCommand,1000,DEBUG); // close connection
    
     }    
   }  
}
 


String sendData(String command, const int timeout, boolean debug)
{
    String response = "";
    
    esp8266.print(command); // send the read character to the esp8266
    
    long int time = millis();
    
    while( (time+timeout) > millis())
    {
      while(esp8266.available())
      {
        
        // The esp has data so display its output to the serial window 
        char c = esp8266.read(); // read the next character.
        response+=c;
      }  
    }
    
    if(debug)
    {
      Serial.print(response);
    }
    
    return response;
}
