class Card
{
  public:
    bool isInside = false;
    char *pinInChar;
    int *pins;
    int *aPins;
    bool *beenPlayed;
    bool *analogBeenPlayed;
    int amountOfPins;
    int amountOfAPins;

    Card(int howManyPins, int howManyAPins)
    {
      pins = new int[howManyPins];
      aPins = new int[howManyAPins];
      pinInChar = new char[howManyPins];
      beenPlayed = new bool[howManyPins];
      analogBeenPlayed = new bool[howManyAPins * 3];
      this->amountOfPins = (int)howManyPins;
      this->amountOfAPins = (int)howManyAPins;

      for (int i = 0; i < howManyPins; i++)
      {
        pinMode(i + 2, INPUT_PULLUP);

        this->pins[i] = i + 2;
        this->pinInChar[i] = '0' + pins[i];
        this->beenPlayed[i] = {false};
      }

      for (int i = 0; i < howManyAPins * 3; i++)
      {
        this->analogBeenPlayed[i] = {false};
      }
    }

    void checkStatus()
    {
      bool noCard = true;
      for (int i = 0; i < amountOfPins; i++)
      {
        if (digitalRead(pins[i]) == 1 && beenPlayed[i] == false)
        {
          Serial.write(pins[i]);
         // Serial.println(pins[i]);
          beenPlayed[i] = true;
          noCard = false;
        }
      }
      for (int i = 0; i < amountOfAPins; i++)
      {
        if (analogRead(i) > 330 && analogRead(i) < 500 && analogBeenPlayed[i] == false)
        {
          //Serial.println("This is analog read 1");
          Serial.write(amountOfPins + i + 2);
          analogBeenPlayed[i] = true;
          noCard = false;
        }
        else if ( analogRead(i) < 330 && analogBeenPlayed[i + 1] == false)
        {
         // Serial.println("This is analog read 2");
          Serial.write(amountOfPins + i + 2);
          analogBeenPlayed[i+1] = true;
          noCard = false;
        }
        else if (analogRead(i) > 900 && analogBeenPlayed[i + 2] == false)
        {
          //Serial.println("This is analog read 3");
          Serial.write(amountOfPins + i + 2);
          analogBeenPlayed[i+2] = true;
          noCard = false;
        }
      }
      if (noCard)
{
  Serial.write(0);
  }

      
    }
};

Card *cards;

void setup()
{
  // put your setup code here, to run once:
  int digitalCards = 7;
  int analogCards = 5;

  Serial.begin(9600);

  //Serial.println("Setup Complete");
  cards = new Card(digitalCards, analogCards);
}

void loop()
{
  // put your main code here, to run repeatedly:
  cards->checkStatus();
}





