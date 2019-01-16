#include <Keyboard.h>

//#include <Mouse.h>


const int buttonPin = 2;
const int manner = 7;
const int neutral = 8;
const int bm = 9;
const int selection = A0;
const int manner_led = 3;
const int neutral_led = 4;
const int bm_led = 5;

void setup() {
 // Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(manner_led, OUTPUT);
  pinMode(neutral_led, OUTPUT);
  pinMode(bm_led, OUTPUT);
  pinMode(selection, INPUT);


  Keyboard.begin();
}

void loop() 
{
  int buttonState;
  int potValue = 0;

  potValue = analogRead(selection);
  buttonState = digitalRead(buttonPin);
  //Serial.println(potValue);

    //Function 1 - manner
    if(potValue >= 0 && potValue < 341)
    {
      digitalWrite(manner_led, HIGH);
      digitalWrite(neutral_led, LOW);
      digitalWrite(bm_led, LOW);
    }
    
    //Function 2 - neutral
    if(potValue >= 341 && potValue < 682)
    {
      digitalWrite(manner_led, LOW);
      digitalWrite(neutral_led, HIGH);
      digitalWrite(bm_led, LOW);
    }

    //Function 3 - bm
    if(potValue >= 682 && potValue < 1023)
    {
      digitalWrite(manner_led, LOW);
      digitalWrite(neutral_led, LOW);
      digitalWrite(bm_led, HIGH);
    }


  if (!buttonState)
  {
    //Function 1 - manner
    if(potValue >= 0 && potValue < 341)
    {
      manner_sub();
    }
    
    //Function 2 - neutral
    if(potValue >= 341 && potValue < 682)
    {
      neutral_sub();
    }

    //Function 3 - bm
    if(potValue >= 682 && potValue < 1023)
    {
      bm_sub();
    }
    
  }

}


//**********************************************************************************
// Function 1 - manner:
// Mental state is good. Be nice to your opponent.
//**********************************************************************************
void manner_sub()
{
  Keyboard.write(0xB0); //enter
  delay(300);
  Keyboard.println("gg wp");
  delay(2000);

  Keyboard.write(0xCB); //F10
  delay(100);
  Keyboard.print("n");
  delay(100);
}



//**********************************************************************************
// Function 2 - neutral:
// You still know that sometimes it's better to just not say anything.
//**********************************************************************************
void neutral_sub()
{
  Keyboard.write(0xCB); //F10
  delay(100);
  Keyboard.print("n");
  delay(100);
}


//**********************************************************************************
// Function 3 - bm:
// This is their fault.
//**********************************************************************************
void bm_sub()
{
  Keyboard.write(0xB0); //enter
  delay(300);
  Keyboard.println("apologize for playing that race");
  delay(1000);

 Keyboard.print("]"); //custom pause key
  delay(500);
  Keyboard.print("]");
  delay(500);
  Keyboard.print("]");
  delay(500);
  Keyboard.print("]");
  delay(500);
  Keyboard.print("]");
  delay(500);

  Keyboard.write(0xCB); //F10
  delay(100);
  Keyboard.print("n");
  delay(100);
}




