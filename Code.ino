#include<Keypad.h>                  // including library for keypad 

const int numRows = 4;       //initialising row and column 
const int numCols = 4;

char keymap[numRows][numCols]=           //initialising keymap
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[numRows] = {9,8,7,6};       //connected row pins of keypad in arduino
byte colPins[numCols] = {5,4,3,2};         // connected column pins of keypad in arduino 

Keypad keypad = Keypad(makeKeymap(keymap),rowPins,colPins,numRows,numCols);     //Initialising keypad



void setup()
{ 
  //Serial.begin(9600);
  pinMode(13,OUTPUT);
   
}

int Getval()             //Function to get the 2 digit number
{
  
  int value = 0;               //initialising value to 0                 
  int keypressed;                                     
  int isnum;
  int count =0;             //initialising number of digits(count) to 0
  do
  {
    keypressed = keypad.getKey();                    //Taking input from keypad 
    isnum = (keypressed >= '0' && keypressed <= '9');     //if input is a number between 0 to 9, isnum = 1
    if(isnum)                  //checks if input is a number, if it is then the if statement is processed , else it is skipped
    {
      value = (value*10) + (keypressed-'0');   //value is multiplied to the next digit place and input is added to it 
      count++;      
    }
    
    if(count >= 2)      //If number of digits are equal o 2, then the value is returned
      return value;
    
  }while(isnum || !keypressed);   //loop runs till input is a number or no key is pressed
 
  
}
void loop()
{
  int value = Getval();   //Getting value from Getval() function
  if(value == 10)
  {
   	digitalWrite(13,HIGH);       //If value = 10 , then LED glows
   }
  if(value == 20)
  {
              digitalWrite(13,LOW);     //if value = 20, then LED stops glowing(if it was glowing)
  }
}
