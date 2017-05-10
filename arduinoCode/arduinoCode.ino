
class Card
{
  public:
    bool isInside = false;
    char *pinInChar;
    int *pins;
    bool *beenPlayed;
    int amountOfPins;

    Card(int howManyPins)
    {
      pins = new int[howManyPins] ;
      pinInChar = new char[howManyPins];
      beenPlayed = new bool[howManyPins];
      this->amountOfPins = (int)howManyPins;
      

      for (int i = 0; i < howManyPins; i++)
      {
        pinMode(i +2, INPUT_PULLUP);

        this->pins[i] = i +2;
        this->pinInChar[i] = '0' + pins[i];
        this->beenPlayed[i] = {false};

      }

    }

    void checkStatus()
    {
      for (int i = 0; i < amountOfPins; i++)
      {

        if (digitalRead(pins[i]) == 1 && beenPlayed[i] == false)
        {
          Serial.write(pins[i]);
          Serial.println(pins[i]);
          beenPlayed[i] = true;
          
          break;
        }
        

      }
      Serial.write(0);
    }
    

};


Card *cards;


void setup() {
  // put your setup code here, to run once:

  int amountOfCards = 3;

  Serial.begin(9600);
  
  Serial.println("Setup Complete");
  cards = new Card(amountOfCards);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  cards->checkStatus();

}




