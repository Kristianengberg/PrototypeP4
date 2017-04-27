#include <stdlib.h>

class Card
{
  public:
  bool isInside = false;
  int pin;
 
    Card(int pin)
  {
    pinMode(pin, INPUT_PULLUP);
    this->pin = pin;
  }
  void isIn()
  {
    Serial.
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
Serial.println(digitalRead(cardOne.pinNumber()));
delay(50);
}



