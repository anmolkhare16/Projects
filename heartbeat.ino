/* =================================================================================================
      Project: Arduino Heart rate monitor
       Author: Scott C
      Created: 21st April 2015
  Arduino IDE: 1.6.2
      Website: http://arduinobasics.blogspot.com/p/arduino-basics-projects-page.html
  Description: This is a simple sketch that uses a Grove Ear-clip Heart Rate sensor attached to an Arduino UNO,
               which sends heart rate data to the computer via Serial communication. You can see the raw data
               using the Serial monitor on the Arduino IDE, however, this sketch was specifically
               designed to interface with the matching Processing sketch for a much nicer graphical display.
               NO LIBRARIES REQUIRED.
=================================================================================================== */

#define Heart 2                            //Attach the Grove Ear-clip sensor to digital pin 2.
#define LED 4                              //Attach an LED to digital pin 4

boolean beat = false;                      /* This "beat" variable is used to control the timing of the Serial communication
                                           so that data is only sent when there is a "change" in digital readings. */

//==SETUP==========================================================================================
void setup() {
  Serial.begin(9600);                     //Initialise serial communication
  pinMode(Heart, INPUT);                  //Set digital pin 2 (heart rate sensor pin) as an INPUT
  pinMode(LED, OUTPUT);                   //Set digital pin 4 (LED) to an OUTPUT
}


//==LOOP============================================================================================
void loop() {
  if(digitalRead(Heart)>0){               //The heart rate sensor will trigger HIGH when there is a heart beat
    if(!beat){                            //Only send data when it first discovers a heart beat - otherwise it will send a high value multiple times
      beat=true;                          //By changing the beat variable to true, it stops further transmissions of the high signal
      digitalWrite(LED, HIGH);            //Turn the LED on 
      Serial.println(1023);               //Send the high value to the computer via Serial communication.
    }
  } else {                                //If the reading is LOW, 
    if(beat){                             //and if this has just changed from HIGH to LOW (first low reading)
      beat=false;                         //change the beat variable to false (to stop multiple transmissions)
      digitalWrite(LED, LOW);             //Turn the LED off.
      Serial.println(0);                  //then send a low value to the computer via Serial communication.
    }
  }
}
