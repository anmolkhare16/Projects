#include <SoftwareSerial.h>

SoftwareSerial mySerial(9,10);

int buzz= 13;
int motor = 3;
int rev = 4;
int i;
int button1= 7;
int button2=11;
int motor1= 5;
int motor2=6;
  int x;
  int y;
  int z;
void setup()
{ mySerial.begin(9600);

   Serial.begin(9600);
     pinMode(button1, INPUT);
 pinMode(button2, INPUT);
 pinMode(buzz, OUTPUT);
 pinMode(motor1, OUTPUT);
 pinMode(motor2, OUTPUT);
 pinMode(motor, OUTPUT);
 pinMode(rev, OUTPUT);

  
  
}
 void loop()
{
  
 
 while(mySerial.available()>0){
 if(mySerial.available()>0)
  {
   i++;
    Serial.write(mySerial.read());
  
  digitalWrite(buzz,HIGH);
 
  delay(50);
 
  digitalWrite(buzz,LOW);
 }
    digitalWrite(motor,HIGH);
    digitalWrite(rev, LOW);
  // while(mySerial.available()0);
  } 
    delay(2000);
    digitalWrite(motor,LOW);
  if(i != 0)
  {
     digitalWrite(rev,HIGH);
     digitalWrite(motor, LOW);
     delay(2600);
     digitalWrite(rev,LOW);
     
      i=0;
        
       if(digitalRead(button1) == HIGH)
      {
        digitalWrite(motor1, HIGH);
        delay(2100);
        digitalWrite(motor1, LOW);
        delay(20);
      }

      if(digitalRead(button2) == HIGH)
      {
        digitalWrite(motor2, HIGH);
        delay(2100);
        digitalWrite(motor2, LOW);
        delay(20);
      }
      x=digitalRead(button1);
      y=digitalRead(button2);
      z = x^y;
       while(z<=0);
   if(digitalRead(button1) == HIGH)
      {
        digitalWrite(motor1, HIGH);
        delay(1990);
        digitalWrite(motor1, LOW);
        delay(20);
      }

      if(digitalRead(button2) == HIGH)
      {
        digitalWrite(motor2, HIGH);
        delay(1990);
        digitalWrite(motor2, LOW);
        delay(20);
      }
 
   }
       
 

    








  
}
