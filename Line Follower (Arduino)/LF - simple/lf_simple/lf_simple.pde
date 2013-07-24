/*
  Analog input, serial output
 
 Reads an analog input pin, prints the results to the serial monitor.
 
 The circuit:

 * potentiometer connected to analog pin 0.
   Center pin of the potentiometer goes to the analog pin.
   side pins of the potentiometer go to +5V and ground
 
 created over and over again
 by Tom Igoe and everyone who's ever used Arduino
 
 This example code is in the public domain. It's practically in the collective unconscious by now too.
 
 */
 int p1=8;
 int p2=9;
 int p3=10;
 int p4=11;
 int p5=1;
 int p6=2;
 int p7=3;
 int k;
 
 void setup() {
  Serial.begin(9600);
  pinMode(p1,OUTPUT);
  pinMode(p2,OUTPUT);
  pinMode(p3,OUTPUT);
  pinMode(p4,OUTPUT);
  k=0;
   pinMode(p5,OUTPUT);
    pinMode(p6,OUTPUT);
     pinMode(p7,OUTPUT);
    
 }
 
 void loop() {
  // read the analog input into a variable:
   //int analogValue = analogRead(0);
   // print the result:
   Serial.println(analogRead(0));
   Serial.println(analogRead(1));
   Serial.println(analogRead(2));
   Serial.println(             );
//delay (1000);
//   if (analogRead(0)<950 && analogRead(1)<475 && analogRead(2)<475)
  // {
    // digitalWrite(p1,LOW);
   //  digitalWrite(p2,LOW);
  //   digitalWrite(p3,LOW);
 //    digitalWrite(p4,LOW);
 //  }

   if (analogRead(0)>250 && analogRead(1)>550 && analogRead(2)>150)
   {
     digitalWrite(p1,HIGH);
     digitalWrite(p2,LOW);
     digitalWrite(p3,HIGH);
     digitalWrite(p4,LOW);
     k=k+1;
     if(k==1)
     { digitalWrite(p5,HIGH);
      digitalWrite(p6,LOW);
       digitalWrite(p7,LOW);
     }
      if(k==2)
     { digitalWrite(p5,LOW);
      digitalWrite(p6,HIGH);
       digitalWrite(p7,LOW);
     }
      if(k==3)
     { digitalWrite(p5,HIGH);
      digitalWrite(p6,HIGH);
       digitalWrite(p7,LOW);
     }
      if(k==4)
     { digitalWrite(p5,LOW);
      digitalWrite(p6,LOW);
       digitalWrite(p7,HIGH);
     }
      if(k==5)
     { digitalWrite(p5,HIGH);
      digitalWrite(p6,LOW);
       digitalWrite(p7,HIGH);
     }
      if(k==6)
     { digitalWrite(p5,LOW);
      digitalWrite(p6,HIGH);
       digitalWrite(p7,HIGH);
     }
      if(k==7)
     { digitalWrite(p5,HIGH);
      digitalWrite(p6,HIGH);
       digitalWrite(p7,HIGH);
     }
   }
    if (analogRead(0)<250 && analogRead(1)>550 && analogRead(2)<125)
   {
     digitalWrite(p1,HIGH);
     digitalWrite(p2,LOW);
     digitalWrite(p3,HIGH);
     digitalWrite(p4,LOW);
   }
   if (analogRead(0)<250 && analogRead(1)>550 && analogRead(2)>125)
   {
     digitalWrite(p1,LOW);
     digitalWrite(p2,HIGH);
     digitalWrite(p3,HIGH);
     digitalWrite(p4,LOW);
   }
    if (analogRead(0)>250 && analogRead(1)<550 && analogRead(2)<125)
   {
     digitalWrite(p1,HIGH);
     digitalWrite(p2,LOW);
     digitalWrite(p3,LOW);
     digitalWrite(p4,HIGH);
   }
   if (analogRead(0)>250 && analogRead(1)>470 && analogRead(2)<125)
   {
     digitalWrite(p1,HIGH);
     digitalWrite(p2,LOW);
     digitalWrite(p3,LOW);
     digitalWrite(p4,HIGH);
   }
    if (analogRead(0)<250 && analogRead(1)<470 && analogRead(2)>125)
   {
     digitalWrite(p1,LOW);
     digitalWrite(p2,HIGH);
     digitalWrite(p3,HIGH);
     digitalWrite(p4,LOW);
   }
   //delay(1000);
   // wait 10 milliseconds for the analog-to-digital converter
   // to settle after the last reading:
 }
