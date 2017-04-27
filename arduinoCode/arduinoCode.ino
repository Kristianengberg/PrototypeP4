#include <stdlib.h>

class Card
{
  public:
  bool isInside = false;
  int pin;
  char pinInChar[];
  int pins[];
 
    Card(int howManyPins)
  {
    pins[howManyPins];
    pinInChar[howManyPins];
    for(int i = 2; i < howManyPins; i++)
    {
    pinMode(i, INPUT_PULLUP);
    this->pins[i-2] = i ;
    this->pinInChar[i-2] = '0' + pin;
    }
    
    
  }
  void checkStatus()
  {
    for(int i = 0; i < sizeof(pins); i++)
    {
    if(digitalRead(pins[i]) == 0)
    {
      isIn(i);
    }
    }

    
  }
  
  void isIn(int whatIsIn)
  {
    Serial.write(whatIsIn);
  }

};




Card cards = Card(1);

void setup() {
  // put your setup code here, to run once:


Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
cards.checkStatus();
delay(50);
}



