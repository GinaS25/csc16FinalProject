#include <iostream>
using namespace std;
#include <string.h>
#include <locale>
#include <vector>
#include <cstdlib>
#include <stdlib.h>
#include <fstream>
#include <boost/algorithm/string/trim.hpp>
#include "Hangman.h"

  enum Categories {PERSON=1,PLACE,THING,FOOD,SPORTS_PERSONALITY,ACTOR};
                 //      1     2    3     4               5       6
  enum BadGuessDraw {HEAD=1,BODY,RT_ARM,LEFT_ARM,RT_LEG,LEFT_LEG, RT_EYE, LEFT_EYE, MOUTH};
                 //      1     2    3         4       5        6       7        8
  const int MaxBadGuesses = 9;   // Max guesses before losing
  const int MaxSize = 20;        // Max letters in answer
  const int HintSize = 30;       // Max size of hint
  const int PoleSize = 4;  //Size of pole in board

  const int MaxTries = MaxBadGuesses+MaxSize;
  char guessedLetters[MaxTries];     // Array to hold the guesses
  //char answer[MaxSize];           // Answer read from file
  string answer;
  char lettersFound[MaxSize];     // String with letters found
  char hint[HintSize];               // Hint string read from file
  char ch;
  int category;
  string categoryDesc;
//  int guessCtr = 0;   //Letters guessed counter
  int badGuessCtr = 0;  //Bad guesses counter
  string AthruM = "A|B|C|D|E|F|G|H|I|J|K|L|M";
  string NthruZ = "N|O|P|Q|R|S|T|U|V|W|X|Y|Z";

//prototype
void printLogo();
void printBoard();
void printKeyboard();
/*
HangMan::Hangman()
{
  MaxBadGuesses = 9;        // Max guesses before losing
  MaxSize = 20;             // Max letters in answer
  HintSize = 30;            // Max size of hint
  MaxTries = MaxBadGuesses+MaxSize;

  //char guessedLetters[MaxTries];     // Array to hold the guesses
  //char answer[MaxSize];           // Answer read from file
  //char lettersFound[MaxSize];     // String with letters found
  //char hint[HintSize];               // Hint string read from file
}
*/

bool displayCat()
{

 //This is a 1 or 2 Player Hangman Game. Players can save the game and reload it 

//Hard coded for now. Must be fixed
category = 1;
//strcpy(answer, "GREECE              ");
//strcpy(hint, "The Parthenon");

  cout<<endl<<"                  CATEGORY: ";
  switch(category)
  {
     case PERSON:
       cout<<"Person"<<endl;
     break;

     case PLACE:
       cout<<"Place"<<endl;
     break;

     case THING:
       cout<<"Thing"<<endl;
     break;

     case SPORTS_PERSONALITY:
       cout<<"Sports Personality"<<endl;
     break;

     case ACTOR:
       cout<<"Actor"<<endl;
     break;

     default:
       cerr<<"Incorrect category in file. Please call support for help."<<endl;
       return true;
  }

  return false;
}

bool playHangman()
{
  // Set strings to spaces
  int ansSize = answer.size()+1;
  for( int i=0; i<ansSize; i++)
    lettersFound[i] = ' ';
  for( int i=0; i<MaxTries; i++)
    guessedLetters[i] = ' ';

  int guessCtr = 0;

  // Run thru for the maximum amount of guesses allowed
  while(badGuessCtr<MaxBadGuesses)
  {
    cout<<endl<<"Letters already selected: ["<<guessedLetters<<"]";
    cout<<endl<<"Please select a letter: ";
    cin >> ch;
    ch = toupper(ch);

    bool alreadyGuessed = false;

    // Check to see if user guessed this letter already
    for( int i=0; i<ansSize; i++)
    {
cout<<"try # "<<i<<endl;
      if(ch == guessedLetters[i])
      {
        cout<<"You already guessed "<<ch<<" . Please guess again."<<endl;
        alreadyGuessed=true;
        break;
      }
    }
    if(alreadyGuessed)
      continue;   //Get another letter

    // Letter not guessed yet. See if it's part of answer
    guessedLetters[guessCtr++] = ch;
    int found = false;

    for( int i=0; i<ansSize; i++)
    {
      if( answer[i] == ch)
      {
        lettersFound[i] = ch;  // Fill the letter into answer string & keep looking
        found=true;
      }
    }

cout<<"Found";
char t;
cin>>t;
   // Check to see if letter was found
   if(found)
   {
     cout<<endl<<"You found a letter: [" << lettersFound << "]" <<endl;
     //Check if game is solved
     for(int i=0;i<ansSize;i++)
     {
       if(lettersFound[i] != answer[i])
       {
         cout<<"Incorrect guess. Please try again."<<endl;
         badGuessCtr++;
         printLogo();
         printBoard();
         continue;
       }
     }
   return true;
   }
  }  //While loop

return false;
}

void printLogo()
{
  system("clear");
  cout<<endl<<endl<<endl<<endl;

  cout <<" _    _      __       _    _  _____   _          __       _    _"<<endl;
  cout <<"| |  | |    /  \\    |\\ \\  | ||  ___||\\ \\  /|    /  \\    |\\ \\  | |"<<endl;
  cout <<"| |__| |   / /\\ \\   | \\ \\ | || |    | \\ \\/ |   / /\\ \\   | \\ \\ | |"<<endl;
  cout <<"|  __  |  / /__\\ \\  | |\\ \\| || | __ | |\\/| |  / /__\\ \\  | |\\ \\| |"<<endl;
  cout <<"| |  | | / /    \\ \\ | | \\ \\ || |_| || |  | | / /    \\ \\ | | \\ \\ |"<<endl;
  cout <<"|_|  |_|/_/      \\_\\|_|  \\_\\||_____||_|  |_|/_/      \\_\\|_|  \\_\\|"<<endl;

  cout<<endl<<endl<<"  Brought to you by Gina Shaw, Kerry McAdams and Tarnjot Parhar"<<endl<<endl;
  return;
}

void printBoard()
{
  cout<<"                  CATEGORY: "<<endl<<endl;

  cout<<"                     ____________"<<endl;
  cout<<"                     |          |"<<endl;
  if(badGuessCtr == 0)
  {
    cout<<"                     |"<<endl;
    cout<<"                     |"<<endl;
    cout<<"                     |"<<endl;
    cout<<"                     |"<<endl;
    cout<<"                     |"<<endl;
    cout<<"                     |"<<endl;
  }

  switch(badGuessCtr)
  {
  case HEAD:
    cout<<"                     |         _|_"<<endl;
    cout<<"                     |        |   |"<<endl;
    cout<<"                     |        |___|"<<endl;
    cout<<"                     |"<<endl;
    cout<<"                     |"<<endl;
    cout<<"                     |"<<endl;
    cout<<"                     |"<<endl;
  break;

  case BODY:
    cout<<"                     |         _|_"<<endl;
    cout<<"                     |        |   |"<<endl;
    cout<<"                     |        |___|"<<endl;
    cout<<"                     |          |"<<endl;
    cout<<"                     |"<<endl;
    cout<<"                     |"<<endl;
    cout<<"                     |"<<endl;
    break;

  case RT_ARM:
    cout<<"                     |         _|_"<<endl;
    cout<<"                     |        |   |"<<endl;
    cout<<"                     |        |___|"<<endl;
    cout<<"                     |          |"<<endl;
    cout<<"                     |          |\\"<<endl;
    cout<<"                     |"<<endl;
    cout<<"                     |"<<endl;
    break;

  case LEFT_ARM:
    cout<<"                     |         _|_"<<endl;
    cout<<"                     |        |   |"<<endl;
    cout<<"                     |        |___|"<<endl;
    cout<<"                     |          |"<<endl;
    cout<<"                     |         /|\\"<<endl;
    cout<<"                     |"<<endl;
    cout<<"                     |"<<endl;
    break;

  case RT_LEG:
    cout<<"                     |         _|_"<<endl;
    cout<<"                     |        |   |"<<endl;
    cout<<"                     |        |___|"<<endl;
    cout<<"                     |          |"<<endl;
    cout<<"                     |         /|\\"<<endl;
    cout<<"                     |          |"<<endl;
    cout<<"                     |           \\"<<endl;
    break;

  case LEFT_LEG:
    cout<<"                     |         _|_"<<endl;
    cout<<"                     |        |   |"<<endl;
    cout<<"                     |        |___|"<<endl;
    cout<<"                     |          |"<<endl;
    cout<<"                     |         /|\\"<<endl;
    cout<<"                     |          |"<<endl;
    cout<<"                     |         / \\"<<endl;
    break;

  case RT_EYE:
    cout<<"                     |         _|_"<<endl;
    cout<<"                     |        |  .|"<<endl;
    cout<<"                     |        |___|"<<endl;
    cout<<"                     |          |"<<endl;
    cout<<"                     |         /|\\"<<endl;
    cout<<"                     |          |"<<endl;
    cout<<"                     |         / \\"<<endl;
    break;

  case LEFT_EYE:
    cout<<"                     |         _|_"<<endl;
    cout<<"                     |        |. .|"<<endl;
    cout<<"                     |        |___|"<<endl;
    cout<<"                     |          |"<<endl;
    cout<<"                     |         /|\\"<<endl;
    cout<<"                     |          |"<<endl;
    cout<<"                     |         / \\"<<endl;
    break;

  case MOUTH:
    cout<<"                     |         _|_"<<endl;
    cout<<"                     |        |. .|"<<endl;
    cout<<"                     |        |_-_|"<<endl;
    cout<<"                     |          |"<<endl;
    cout<<"                     |         /|\\"<<endl;
    cout<<"                     |          |"<<endl;
    cout<<"                     |         / \\"<<endl;
    break;
  }

  cout<<"                   __|________________"<<endl;
  cout<<"                  /  |               /|"<<endl;
  cout<<"                 /__________________/ |"<<endl;
  cout<<"                 |__________________|/ "<<endl;
  if(badGuessCtr != MaxBadGuesses)
    printKeyboard();

  return;
}

void printKeyboard()
{
  cout<<endl<<"               ____________________________  "<<endl;
  cout<<"              | "<<AthruM<<" |"<<endl;
  cout<<"              | "<<NthruZ<<" | "<<endl;
  cout<<"              |___________________________|  "<<endl<<endl;
  return;
}

bool readFile()
{
  // Create a vector to store file contents.
  vector <string> wordVec;

  // Open a file stream to the file with Hangman names
  ifstream fileName("hmwords.txt");

  // Make sure file exists and read it
  if(!fileName.good())
  {
    cout<<"Unable to locate word file. Please contact Customer Support"<<endl;
    return true;
  }

  string line;
  line.clear();

  // Read each line in the file and place into vector
  while(getline(fileName, line))
    wordVec.push_back(line);  // append to vector and increase size

  // Use a random generator to get the line in the vector for the answer
  srand(time(NULL));
  int randomRange = 0;
  randomRange = rand()% wordVec.size();

  // Store the line with the answer
  line.clear();  //clearing line again
  line = wordVec.at(randomRange);

  string str = line.substr(21);
  int hintSize = str.size();
  answer = line.substr(1,20);
  boost::algorithm::trim(answer);  
cout<<answer<<endl;
cout<<"ans size="<<answer.size();

cout<<"hint size: "<<hintSize<<endl;
cout<<"hint: "<<str<<endl;
  // Close the file stream
  fileName.close();

  // Convert category from ascii to integer by subtracting 48
  int category = line[0] - 48;
//  if(readCategoryFile(category))
  //   return true;
  return false;
}

bool readCategoryFile(int cat)
{

cout<<endl<<"in cat "<<cat<<endl;;
  // Open a file stream to the file with Hangman names
  ifstream catFileName("categories.txt");

  // Make sure file exists and read it
  if(!catFileName.good())
  {
    cout<<"Unable to locate categories.txt file. Please contact Customer Support"<<endl;
    return true;
  }

  string line;

  // Read each line in the file and find category
  while(getline(catFileName, line,'\r'))
  {
    int temp = line[0] - 48;
    cout<<"temp = "<<temp<<endl;
    if(temp == cat);  // get description
    {
      //cout<<line<<endl;
      // Close the file stream
      catFileName.close();
      return false;
    }
  }
 cout<<"Category not found. Please call Customer Support";

 // Close the file stream
 catFileName.close();
 return true;
}

