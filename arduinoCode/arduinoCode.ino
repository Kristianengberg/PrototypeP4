#include <stdlib.h>

class Card
{
  public:
    bool isInside = false;
    char *pinInChar;
    int *pins;
    int amountOfPins;

    Card(int howManyPins)
    {
      pins = new int[howManyPins] ;
      pinInChar = new char[howManyPins];
      this->amountOfPins = (int)howManyPins;

      for (int i = 0; i < howManyPins; i++)
      {
        pinMode(i + 2, INPUT_PULLUP);

        this->pins[i] = i + 2;
        this->pinInChar[i] = '0' + pins[i];

      }

    }

    void checkStatus()
    {
      for (int i = 0; i < amountOfPins; i++)
      {

        if (digitalRead(pins[i]) == 0)
        {
          Serial.write(pins[i]);
          break;
        }

      }
      Serial.write(0);
    }

};


Card *cards;


void setup() {
  // put your setup code here, to run once:

  int amountOfCards = 12;

  Serial.begin(9600);
  cards = new Card(amountOfCards);

}

void loop() {
  // put your main code here, to run repeatedly:
  cards->checkStatus();

}



