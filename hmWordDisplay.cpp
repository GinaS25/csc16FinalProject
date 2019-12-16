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
  int ansSize = answer.size();
  char guessedLetters[MaxTries] = {' '};

  //for( int i=0; i<ansSize; i++)
  lettersFound = string(ansSize, ' ');
  int guessCtr = 0;
  badGuessCtr = EMPTY;

  printLogo();
  printBoard(guessedLetters);
  // Run thru for the maximum amount of guesses allowed
  while(badGuessCtr<MaxBadGuesses)
  {
cout<<"Guessed letters: ["<<guessedLetters<<"]";
    cout<<endl<<"Please select a letter. Type '?' for a hint: ";
    char ch;
    cin >> ch;
    ch = toupper(ch);

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

    solved = false;
    int i = 0;

   // Check to see if letter was found
   if(found)
   {
     printWord();
     //Letter found. Check if game is solved
     for(i=0;i<ansSize;i++)
     {
       if(lettersFound[i] != answer[i])
        break;
     }
     if(i == ansSize)
       solved = true;
   }
   else    // Letter not found
   {
     cout<<"Incorrect guess. Please try again."<<endl;
     badGuessCtr++;
     printLogo();
     printBoard(guessedLetters);
     continue;
    }

  printLogo();
  printBoard(guessedLetters);

  if(solved)
      return true;
  }  //While loop

return false;
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

  string str = line.substr(MaxSize+1);
  int hintSize = str.size();
  answer = line.substr(1,MaxSize);
  boost::algorithm::trim(answer);  

cout<<answer<<endl;

  hint = line.substr(MaxSize+1,hintSize);
  // Close the file stream
  fileName.close();

  // Convert category from ascii to integer by subtracting 48
  int category = line[0] - 48;
  if(readCategoryFile(category))
    return true;
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

void printBoard(string guesses)
{
  cout<<"                  Category: "<<categoryDesc<<endl<<endl;
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
    return;
  }

  cout<<"                     ____________"<<endl;
  cout<<"                     |          |"<<endl;

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

  cout<<"                   __|________________"<<endl;
  cout<<"                  /  |               /|"<<endl;
  cout<<"                 /__________________/ |"<<endl;
  cout<<"                 |__________________|/ "<<endl;
  if(badGuessCtr != MaxBadGuesses)
    printKeyboard(guesses);

  return;
}

void printWord()
{
  //variables for centering the word
  int lengthOfKeyboard = 47;
  int spaceNum;
  int sideSpaceNum;
  string space;

  //sets blank string
  string underscore = string(answer.size(), ' ');

  //for loop to add letters as they're being guessed
  for(int i=0;i<answer.size(); i++)
  {
    if(lettersFound[i] == answer[i]);
      underscore[i] = lettersFound[i];
  }

  //centers the word being guissed based on word and keyboard size
  if(underscore.size()<lengthOfKeyboard)
  {
    spaceNum = lengthOfKeyboard - underscore.size();
    sideSpaceNum = spaceNum/2;
    space = string(sideSpaceNum,' ');
    cout<<space<<"     *"<<underscore<<"*"<<space<<endl;
  }
}

void printKeyboard(string guess)
{
 cout<<endl;
 printWord();
 cout<<"            -----------------------------------"<<endl;
 string s;
 cout<<"           |                                   |"<<endl;
 cout<<"           |     ";
   for (char i = 'A'; i <= 'M'; i++)
   {
     if (guess.find(i) == string::npos)
     {
       s += i;
       s += " ";
     }
     else
       s += "  ";
   }
 cout<<s<<"    |"<<endl;
 string l;
 cout<<"           |     ";
   for (char i = 'N'; i <= 'Z'; i++)
   {
     if (guess.find(i) == string::npos)
     {
       l += i;
       l += " ";
     }
     else
       l += "  ";
   }
 cout<<l<<"    |"<<endl;
 cout<<"           |                                   |"<<endl;
 cout<<"            -----------------------------------"<<endl;
}
