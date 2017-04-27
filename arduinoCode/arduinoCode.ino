#include <stdlib.h>

class Card
{
  public:
  bool isInside = false;
  int pin;
  char pinInChar;
 
    Card(int pin)
  {
    pinMode(pin, INPUT_PULLUP);
    this->pin = pin;
    this->pinInChar = '0' + pin;
  }
  void checkStatus()
  {
    if(digitalRead(pin) == 0 && isInside == false)
    {
      isIn();
    }
    else return;
    
  }
  
  void isIn()
  {
    isInside = true;
    Serial.write(pinInChar);
  }
  int pinNumber()
  {
    return pin;
  }

};




Card cardOne = Card(2);

void setup() {
  // put your setup code here, to run once:


Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
cardOne.checkStatus();
delay(50);
}



