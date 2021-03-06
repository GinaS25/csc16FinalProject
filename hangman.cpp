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

bool playHangman()
{
  // Set strings to spaces
  ansSize = answer.size();
  char guessedLetters[MaxTries] = {' '};
  allLetters = string(MaxTries, ' ');     // Copy of guessedLetters created to use for keyboard 
  lettersFound = string(ansSize, ' ');

  int guessCtr = 0;
  badGuessCtr = EMPTY;
  solved = false;

  printLogo();
  printBoard();
  // Run thru for the maximum amount of guesses allowed
  while(badGuessCtr<MaxBadGuesses)
  {
    cout<<endl<<"Please select a letter. Type '?' for a hint: ";
    char ch;
    cin >> ch;
    ch = toupper(ch);

    // check if user is asking for a hint
    if(ch == '?')
    { 
     cout<<"Hint: "<<hint<<endl<<endl;
     continue;
    }

    bool alreadyGuessed = false;

    // Check to see if user guessed this letter already
    for(int i=0; i<ansSize; i++)
    {
      if(guessedLetters[i] == ch)
      {
       	cout<<"You already guessed "<<ch<<" . Please guess again."<<endl;
        alreadyGuessed=true;
        break;
      }
    }
    if(alreadyGuessed)
      continue;   //Get another letter

    // Letter not guessed yet. See if it's part of answer
    allLetters += ch;
    cout<<"All Letters = "<<allLetters<<endl;
    
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
    int i = 0;

   // Check to see if letter was found
   if(found)
   {
     //Letter found. Check if game is solved
     for(i=0;i<ansSize;i++)
     {
       if(lettersFound[i] != answer[i])
        break;
     }
     if(i == ansSize)
       solved = true;
   }
   else    // letter not found
   {
     cout<<"Incorrect guess. Please try again."<<endl;
     badGuessCtr++;
     printLogo();
     printBoard();
     continue;
   }

   // display board
  printLogo();
  printBoard();

  // check if game was solved
  if(solved)
      return true;
  }  //While loop

  // game was not solved
  return false;
}

bool readAnsFile()
{
  // Create a vector to store file contents.
  vector <string> wordVec;

  // Open a file stream to the file with Hangman names
  ifstream fileName("hmwords.txt");

  // Make sure file exists and read it
  if(!fileName.good())
  {
    cout<<"Unable to locate word file. Please contact Customer Support"<<endl;
    return true;  //return error found
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

  string str = line.substr(MaxSize+1);
  int hintSize = str.size();
  answer = line.substr(1,MaxSize);
  boost::algorithm::trim(answer);  

  // get the hint for this answer
  hint = line.substr(MaxSize+1,hintSize);

  // Close the file stream
  fileName.close();

  // Convert category from ascii to integer by subtracting 48
  int category = line[0] - 48;

  // get category description
  if(readCategoryFile(category))
    return true;    //return error found

  // return no errors found
  return false;
}

bool readCategoryFile(int cat)
{
  // Open a file stream to the file with Hangman names
  ifstream catFileName("categories.txt");

  // Make sure file exists and read it
  if(!catFileName.good())
  {
    cout<<"Unable to locate categories.txt file. Please contact Customer Support"<<endl;
    return true;
  }

  string line;
  line.clear();
  // Read each line in the file and find category
  while(getline(catFileName, line))
  {
    int temp = line[0] - 48;
    if(temp == cat)  // get description
    {
      categoryDesc = line.substr(1,MaxCatSize);
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

void printLogo()
{
  //Print out Hangman logo
  //system("clear");
  cout<<endl<<endl<<endl<<endl;

  cout <<"  _    _      __       _    _  _____   _          __       _    _"<<endl;
  cout <<" | |  | |    /  \\    |\\ \\  | ||  ___||\\ \\  /|    /  \\    |\\ \\  | |"<<endl;
  cout <<" | |__| |   / /\\ \\   | \\ \\ | || |    | \\ \\/ |   / /\\ \\   | \\ \\ | |"<<endl;
  cout <<" |  __  |  / /__\\ \\  | |\\ \\| || | __ | |\\/| |  / /__\\ \\  | |\\ \\| |"<<endl;
  cout <<" | |  | | / /    \\ \\ | | \\ \\ || |_| || |  | | / /    \\ \\ | | \\ \\ |"<<endl;
  cout <<" |_|  |_|/_/      \\_\\|_|  \\_\\||_____||_|  |_|/_/      \\_\\|_|  \\_\\|"<<endl;

  cout<<endl<<endl<<"   Brought to you by Gina Shaw, Kerry McAdams and Tarnjot Parhar"<<endl<<endl;
  return;
}

void printBoard()
{
  // print out the board according to progress in the game
  cout<<"                  Category: "<<categoryDesc<<endl<<endl;

  // Game solved. Print out free hangman
  if(solved)
  {
    cout<<"                            ___"<<endl;
    cout<<"                           |. .|"<<endl;
    cout<<"                           |_-_|"<<endl;
    cout<<"                             |"<<endl;
    cout<<"                            \\|/"<<endl;
    cout<<"                    _________|_________"<<endl; 
    cout<<"                   /        / \\       /|"<<endl;
    cout<<"                  /__________________/ |"<<endl;
    cout<<"                  |__________________|/ "<<endl;
     // print out answer
    printWord();
    return;
  }

  // print out top of gallow
  cout<<"                     ____________"<<endl;
  cout<<"                     |          |"<<endl;

  // Print out progress based on how many bad guesses there are
  switch(badGuessCtr)
  {
  case EMPTY:
    cout<<"                     |"<<endl;
    cout<<"                     |"<<endl;
    cout<<"                     |"<<endl;
    cout<<"                     |"<<endl;
    cout<<"                     |"<<endl;
    cout<<"                     |"<<endl;
    break;

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

  case LEFT_ARM:
    cout<<"                     |         _|_"<<endl;
    cout<<"                     |        |   |"<<endl;
    cout<<"                     |        |___|"<<endl;
    cout<<"                     |          |"<<endl;
    cout<<"                     |         /|"<<endl;
    cout<<"                     |"<<endl;
    cout<<"                     |"<<endl;
    break;

  case RT_ARM:
    cout<<"                     |         _|_"<<endl;
    cout<<"                     |        |   |"<<endl;
    cout<<"                     |        |___|"<<endl;
    cout<<"                     |          |"<<endl;
    cout<<"                     |         /|\\"<<endl;
    cout<<"                     |"<<endl;
    cout<<"                     |"<<endl;
    break;

  case LEFT_LEG:
    cout<<"                     |         _|_"<<endl;
    cout<<"                     |        |   |"<<endl;
    cout<<"                     |        |___|"<<endl;
    cout<<"                     |          |"<<endl;
    cout<<"                     |         /|\\"<<endl;
    cout<<"                     |          |"<<endl;
    cout<<"                     |         /"<<endl;
    break;

  case RT_LEG:
    cout<<"                     |         _|_"<<endl;
    cout<<"                     |        |   |"<<endl;
    cout<<"                     |        |___|"<<endl;
    cout<<"                     |          |"<<endl;
    cout<<"                     |         /|\\"<<endl;
    cout<<"                     |          |"<<endl;
    cout<<"                     |         / \\"<<endl;
    break;

  case LEFT_EYE:
    cout<<"                     |         _|_"<<endl;
    cout<<"                     |        |.  |"<<endl;
    cout<<"                     |        |___|"<<endl;
    cout<<"                     |          |"<<endl;
    cout<<"                     |         /|\\"<<endl;
    cout<<"                     |          |"<<endl;
    cout<<"                     |         / \\"<<endl;
    break;

 case RT_EYE:
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

  // print out base
  cout<<"                   __|________________"<<endl;
  cout<<"                  /  |               /|"<<endl;
  cout<<"                 /__________________/ |"<<endl;
  cout<<"                 |__________________|/ "<<endl;

  // If didn't lose, print out keyboard
  if(badGuessCtr <= MaxBadGuesses)
  {
    printWord();
    printKeyboard();
  }
  else
    printWord();
  return;
}

void printKeyboard()
{
    // Print out the keyboard. Remove letters that are already guessed
   cout<<endl<<"            -----------------------------------"<<endl;
   string topRow;
   cout<<"           |                                   |"<<endl;
   cout<<"           |     ";
   for (char i = 'A'; i <= 'M'; i++)
   {
     if (allLetters.find(i) == string::npos)
     {
       topRow += i;
       topRow += " ";
     }
     else
       topRow += "  ";
   }
   cout<<topRow<<"    |"<<endl;
   string bottomRow;
   cout<<"           |     ";
   for (char i = 'N'; i <= 'Z'; i++)
   {
     if (allLetters.find(i) == string::npos)
     {
       bottomRow += i;
       bottomRow += " ";
     }
     else
       bottomRow += "  ";
   }
   cout<<bottomRow<<"    |"<<endl;
   cout<<"           |                                   |"<<endl;
   cout<<"            -----------------------------------"<<endl;
}

void printWord()
{
  //variables for centering the word
  int lengthOfKeyboard = KeyboardLen;
  int spaceNum;
  int sideSpaceNum;
  string space;
  int displayLen = ansSize + (ansSize-1);  // add for space between letters
  string displayWord[displayLen];

  //centers the word being guessed based on word and keyboard size
  if(displayLen<lengthOfKeyboard)
  {
    spaceNum = lengthOfKeyboard - displayLen;
    sideSpaceNum = spaceNum/2;
    space = string(sideSpaceNum,' ');
    cout<<endl<<endl<<space<<"     ";
  }

  if(badGuessCtr < MaxBadGuesses)  //Still playing or won
  {
    //  Print out answer. Use underscore character for missing letters
    for(int i=0; i<ansSize; i++)
    {
     if(answer[i] == ' ')
       cout<<"  ";
     else if(lettersFound[i] == ' ')
       cout<<"_ ";
     else
       cout<<lettersFound[i]<<" ";
     }
  }
  else  //lost - print answer
  {
    for(int i=0; i<ansSize; i++)
    {
     if(answer[i] == ' ')
       cout<<"  ";
     else 
       cout<<answer[i]<<" ";
     }
  }
  cout<<endl<<endl;
}
