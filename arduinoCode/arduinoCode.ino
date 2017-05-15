class Card
{
  public:
    bool isInside = false;
    char *pinInChar;
    int *pins;
    int *aPins;
    bool *beenPlayed;
    int j=0;
    //bool *analogBeenPlayed;
    bool analogBeenPlayed[5][3];
    int amountOfPins;
    int amountOfAPins;
    int amountOfATwoPins;
    bool *analogTwoBeenPlayed;

    Card(int howManyPins, int howManyAPins, int howManyATwoPins)
    {
      pins = new int[howManyPins];
      aPins = new int[howManyAPins];
      pinInChar = new char[howManyPins];
      beenPlayed = new bool[howManyPins];
      
      analogTwoBeenPlayed = new bool[howManyATwoPins * 2];
      this->amountOfPins = (int)howManyPins;
      this->amountOfAPins = (int)howManyAPins;
      this->amountOfATwoPins = (int)howManyATwoPins ;


      for (int i = 0; i < howManyPins; i++)
    {
      pinMode(i + 2, INPUT_PULLUP);

        this->pins[i] = i + 2;
        this->pinInChar[i] = '0' + pins[i];
        this->beenPlayed[i] = {false};
      }

      for (int i = 0; i < 5; i++)
    {
      for (int j = 0; j < 3 ; j++)
      {
        this->analogBeenPlayed[i][j] = false;
      }
      
      }
      for (int i = 0; i < howManyATwoPins * 2; i++)
      {
        this->analogTwoBeenPlayed[i] = {false};
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
          //Serial.println(pins[i]);
          beenPlayed[i] = true;
          noCard = false;
        }
      }
      for (int i = 0; i < amountOfAPins; i++)
      {
        
        if (analogRead(i) > 330 && analogRead(i) < 500 && analogBeenPlayed[i][0] == false)
        {
          //Serial.println("This is analog read 1");
          Serial.write(amountOfPins + i + 2);
          analogBeenPlayed[i][0] = true;
          noCard = false;
        }
        else if ( analogRead(i) < 330 && analogBeenPlayed[i][1] == false)
        {
          //Serial.println("This is analog read 2");
          Serial.write(amountOfPins + i + 2);
          analogBeenPlayed[i][1] = true;
          noCard = false;
        }
        else if (analogRead(i) > 900 && analogBeenPlayed[i][2] == false)
        {
          //Serial.println("This is analog read 3");
          Serial.write(amountOfPins + i + 2);
          analogBeenPlayed[i][2] = true;
          noCard = false;
        }
      }

      for (int i = 0; i < amountOfATwoPins; i++)
      {
        if (analogRead(4) > 330 && analogRead(4) < 500 && analogTwoBeenPlayed[i] == false)
        {
          //Serial.println("This is analog read 1");
          Serial.write(13);
          analogTwoBeenPlayed[i] = true;
          noCard = false;
        }
        else if (analogRead(4) > 900 && analogTwoBeenPlayed[i + 1] == false)
        {
          //Serial.println("This is analog read 3");
          Serial.write(13);
          analogTwoBeenPlayed[i + 1] = true;
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
  int analogCards = 4;
  int analogTwoCards = 1;

  Serial.begin(9600);

  //Serial.println("Setup Complete");
  cards = new Card(digitalCards, analogCards, analogTwoCards);
}

void loop()
{
  // put your main code here, to run repeatedly:
  cards->checkStatus();
}





