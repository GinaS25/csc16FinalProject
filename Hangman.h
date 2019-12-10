#ifndef HANGMAN_H
#define HANGMAN_H

#include<iostream>

  enum Categories {PERSON, PLACE, THING};
  const int MaxBadGuesses = 9;        // Max guesses before losing
  const int MaxSize = 20;             // Max letters in answer
  const int HintSize = 30;            // Max size of hint

  const int MaxTries = MaxBadGuesses+MaxSize;
  char guessedLetters[MaxTries];     // Array to hold the guesses
  char answer[MaxSize];           // Answer read from file
  char lettersFound[MaxSize];     // String with letters found
  char hint[HintSize];               // Hint string read from file
  char ch;
  int category;
  int guessCtr = 0;   //Letters guessed counter
  int badGuessCtr = 0;  //Bad guesses counter

/*
class Hangman
{
private:
  enum Categories {PERSON, PLACE, THING};
  const int MaxGuesses = 9;           // Max guesses before losing
  const int MaxLetters = 20;          // Max letters in answer
  const int HintSize = 30;            // Max size of hint

public:
}
*/
#endif //HANGMAN_H
