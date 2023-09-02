#include<Wire.h>
#define led 3 
int intensity = 0;
int b1;
int b2;
void setup()
{
  Wire.begin();
  Serial.begin(9600);
  pinMode(led,OUTPUT);
}

void loop()
{ Wire.requestFrom(8,2);
  if(Wire.available())
  {
   b1 = Wire.read();
   b2= Wire.read();
   
  }
  if(b1 == HIGH && b2 == HIGH)
  {  analogWrite(led,255);
   Serial.println("Glitch");
    
   }
  else if(b1 == HIGH )
  { analogWrite(led,128);
   Serial.println("Vector Focused");
    
   }
  else if(b2 == HIGH )
  { analogWrite(led,192);
    Serial.println("Vector Distracted");
   }
    else
    {
    analogWrite(led,0);
      
      }
 
}