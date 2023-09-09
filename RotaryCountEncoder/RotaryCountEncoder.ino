#define PIN_ENCODER_A 2
#define PIN_ENCODER_B 3

int counter  = 0;


void ISR_encoderPinA()
{
  if(digitalRead(PIN_ENCODER_A)!=digitalRead(PIN_ENCODER_B))
    counter++;
   else
    counter--;
}

void ISR_encoderPinB()
{
  if(digitalRead(PIN_ENCODER_A)==digitalRead(PIN_ENCODER_B))
    counter++;
   else
    counter--;
}
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(PIN_ENCODER_A,INPUT_PULLUP);
pinMode(PIN_ENCODER_B,INPUT_PULLUP);

attachInterrupt(digitalPinToInterrupt(PIN_ENCODER_A),ISR_encoderPinA,CHANGE);
attachInterrupt(digitalPinToInterrupt(PIN_ENCODER_B),ISR_encoderPinB,CHANGE);


}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.print("Counter: ");
  Serial.println(counter);

}
