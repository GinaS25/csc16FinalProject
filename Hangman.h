#ifndef HANGMAN_H
#define HANGMAN_H

#include<iostream>

  enum Categories {PERSON=1,PLACE,THING,FOOD,SPORTS_PERSONALITY,ACTOR};
                 //      1     2    3     4               5       6
  enum BadGuessDraw {EMPTY,HEAD,BODY,LEFT_ARM, RT_ARM,LEFT_LEG,RT_LEG, LEFT_EYE, RT_EYE, MOUTH};
                 //      1     2    3         4       5        6       7        8
  const int MaxBadGuesses = 9;   // Max guesses before losing
  const int MaxSize = 20;        // Max letters in answer
  const int MaxCatSize = 25;   //Max size of category description
  const int PoleSize = 4;  //Size of pole in board
  const int MaxTries = MaxBadGuesses+MaxSize;
  const int KeyboardLen = 47;

  string answer;
  int ansSize = 0;
  string lettersFound;     // String with letters found
  string hint;
  char ch;
  bool solved;
  int category;
  string categoryDesc;
  int badGuessCtr = 0;  //Bad guesses counter

  /* prototypes */
  void printLogo();
  void printBoard();
  void printKeyboard();
  bool readCategoryFile(int cat);
  void printWord();
#endif //HANGMAN_H
