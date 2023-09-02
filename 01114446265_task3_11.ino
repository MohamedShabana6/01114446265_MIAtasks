#include<Wire.h>
#define Button1  4
#define Button2 5




void sendButtons();


void setup()
{
  Serial.begin(9600);
 Wire.begin(8);
  pinMode(Button1,INPUT);
  pinMode(Button2,INPUT);
  Wire.onRequest(sendButtons);
}

void loop()
{
 
    
  
}
 void sendButtons()
 { int buttonState1 = digitalRead(Button1);
  
   int buttonState2 = digitalRead(Button2);
  
  Wire.write(buttonState1);
  Wire.write(buttonState2);
   
 }