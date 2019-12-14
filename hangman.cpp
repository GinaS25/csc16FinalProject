#include <iostream>
using namespace std;
#include <string.h>
#include <locale>
#include <vector>
#include <cstdlib>
#include <stdlib.h>
#include "Hangman.h"

bool tempName();

bool tempName()
{

/* This is a 1 or 2 Player Hangman Game. Players can save the game and reload it */

//Hard coded for now. Must be fixed
category = 1;
strcpy(answer, "GREECE              ");
strcpy(hint, "The Parthenon");

  cout<<endl<<"CATEGORY: ";
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

     default:
       cerr<<"Incorrect category in file. Please call support for help."<<endl;
       return true;
  }

  return false;
}

bool PlayHangman()
{
/*
  // Set strings to spaces
  for( int i=0; i<MaxSize; i++)
    lettersFound[i] = ' ';
  for( int i=0; i<MaxTries; i++)
    guessedLetters[i] = ' ';

  // Run thru for the maximum amount of guesses allowed
  while(badGuessCtr<MaxBadGuesses)
  {
    cout<<endl<<"Letters already selected: <"<<guessedLetters<<">";
    cout<<endl<<"Please select a letter: ";
    cin >> ch;
    ch = toupper(ch);

    bool alreadyGuessed = false;

    // Check to see if user guessed this letter already
    for( int i=0; i<MaxTries; i++)
    {
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
    for( int i=0; i<MaxSize; i++)
    {
      if( answer[i] == ch)
      {
        lettersFound[i] = ch;  // Fill the letter into answer string & keep looking
        found=true;
      }
    }

   // Check to see if letter was found
   if(found)
   {
     cout<<endl<<"You found a letter: <" << lettersFound << ">" <<endl;
     //Check if game is solved
     if(strcmp(lettersFound, answer) == 0)
       return true;
   }
   else
   {
      cout<<"Incorrect guess. Please try again."<<endl;
      badGuessCtr++;
   }
  }
*/
return false;
}

void printLogo()
{
  system("clear");
  cout <<endl<<endl<< "Welcome to"<<endl<<endl;

  cout <<" _    _      __       _    _  _____    _          __       _    _"<<endl;
  cout <<"| |  | |    /  \\    |\\ \\  | ||  ___| |\\ \\  /|    /  \\    |\\ \\  | |"<<endl;
  cout <<"| |__| |   / /\\ \\   | \\ \\ | || |     | \\ \\/ |   / /\\ \\   | \\ \\ | |"<<endl;
  cout <<"|  __  |  / /__\\ \\  | |\\ \\| || | __  | |\\/| |  / /__\\ \\  | |\\ \\| |"<<endl;
  cout <<"| |  | | / /    \\ \\ | | \\ \\ || |_| | | |  | | / /    \\ \\ | | \\ \\ |"<<endl;
  cout <<"|_|  |_|/_/      \\_\\|_|  \\_\\||_____| |_|  |_|/_/      \\_\\|_|  \\_\\|"<<endl;

  cout<<endl<<endl<<"Brought to you by Gina Shaw, Kerry McAdams and Tarnjot Parhar"<<endl<<endl;
  return;
}

void printBoard()
{
  cout<<"       ____________"<<endl;
  cout<<"       |          |"<<endl;
  for(int i = 0; i < PoleSize; i++)
    cout <<"       |"<<endl;
  cout<<"     __|________________"<<endl;
  cout<<"    /  |               /|"<<endl;
  cout<<"   /__________________/ |"<<endl;
  cout<<"   |__________________|/ "<<endl;
  return;
}
