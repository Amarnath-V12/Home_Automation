#include<Servo.h>
Servo servo1 , servo2 ;
int led1=11;
int led2=12;
int fan1 = 9;
int fan2 = 10;
int song = 8;
String voice;

// declare the output
void setup() {
servo1.attach(7);
servo2.attach(6);
servo1.write(0); 
servo2.write(90); 
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(fan1,OUTPUT);
pinMode(song,OUTPUT);
Serial.begin(9600); //to enable the serial communication choose the baud rate
}

void loop() {
  if (Serial.available()>0)
  {
    voice="";
    voice=Serial.readString();
    Serial.print(voice+'\n');
  }
   if(voice=="*light on#")
  {
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  }
  else if (voice=="*turn the light off#")
  {
  digitalWrite(led1,LOW);  
  digitalWrite(led2,LOW);
  }
  else if (voice=="*fan on#")
  {
  digitalWrite(fan1,HIGH); 
  digitalWrite(fan2,LOW);  
  
  }
  else if (voice=="*turn the fan off#")
  {
  digitalWrite(fan1,LOW);  
  digitalWrite(fan2,LOW); 
  }
  else if (voice=="*open the door#")
  {
  servo1.write(90); 
  servo2.write(0);
  }
  else if (voice=="*close the door#")
  {
  servo1.write(0); 
  servo2.write(90);   
  }
  
  else if (voice=="*alarm on#")
  {
  
  digitalWrite(song,HIGH);
  }
  else if (voice=="*turn alarm off#")
  {
  digitalWrite(song,LOW);
  }
}
