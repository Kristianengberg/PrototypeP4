#include <stdlib.h>

class Card
{
  public:
  bool isInside = false;
  char *pinInChar;
  int *pins;
 
    Card(int howManyPins)
  {
    pins = new int[howManyPins] ;
    pinInChar = new char[howManyPins];
    
    
    for(int i = 0; i < sizeof(pins); i++)
    {
      
    this->pins[i] = i+2;
    this->pinInChar[i] = '0' + pins[i];
    pinMode(i+2, INPUT_PULLUP); 
 
    }
    
    
  }
  
  
  void isIn(int whatIsIn)
  {
    Serial.print(pinInChar[whatIsIn]);
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
  checkStatus();
    
  }

};



Card cards = Card(10);

void setup() {
  // put your setup code here, to run once:


  
Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:
cards.checkStatus();

}



