#ifndef HANGMAN_H
#define HANGMAN_H

#include<iostream>

  enum Categories {PERSON,PLACE,THING,FOOD,SPORTS_PERSONALITY,ACTORS};
                 //  0      1     2    3     4                  5 
  const int MaxBadGuesses = 9;        // Max guesses before losing
  const int MaxSize = 20;             // Max letters in answer
  const int HintSize = 30;            // Max size of hint
  const int PoleSize = 4;  //Size of pole in board

  const int MaxTries = MaxBadGuesses+MaxSize;
  char guessedLetters[MaxTries];     // Array to hold the guesses
  char answer[MaxSize];           // Answer read from file
  char lettersFound[MaxSize];     // String with letters found
  char hint[HintSize];               // Hint string read from file
  char ch;
  int category;
  int guessCtr = 0;   //Letters guessed counter
  int badGuessCtr = 0;  //Bad guesses counter

class HangMan
{
private:

public:
  bool PlayHangman();
  bool readFile();
  void printLogo();
  void printBoard();
  //Board();
  //~Board();
};

#endif //HANGMAN_H
