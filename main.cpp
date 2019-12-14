#include <iostream>
using namespace std;
#include <string.h>
//#include <cstring>
#include <locale>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>
#include <sstream>
#include "Hangman.h"

/* prototype*/
bool PlayHangman();
bool readFile();
void printLogo();
void printBoard();

/* This is a 1 or 2 Player Hangman Game. Players can save the game and reload it */

int main()
{
  printLogo();
  printBoard();
  cout<<endl<< "Please enter your name or '!' to Exit: ";
  string playerName;
  cin >> playerName;

//  if(playerName[0] == '!')
//   return 0;

  // Play hangman until user exits
  for(;;)
  {
    if(readFile())
      return 0;
    if(PlayHangman())
      cout<<endl<<"Congratulations "<<playerName<< "! You won!!! ";
    else
      cout<<endl<<"Game Over. ";

    cout <<endl<<endl<< "Do you want to play again? Enter 'Y' for Yes or 'X' to Exit: ";
    char ch;  
    cin >> ch;
   // if (toupper(ch) != 'Y' )
      break;
  }
  return 0;
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
    cout<<"Unable to locate word file. Please contact Customer Support."<<endl;
    return true;
  }

  int count;
  string line;

  // Read each line in the file and place into vector
  while(getline(fileName, line))
  {
    wordVec.push_back(line);  // append to vector and increase size when full
    line = wordVec[count++];
  }

  // Use a random generator to get the line in the vector for the answer
  srand(time(NULL));
  int randomRange = 0;
  randomRange = rand()% wordVec.size();

  // Store the line with the answer
  line = wordVec.at(randomRange);

  // Close the file stream
  fileName.close();

  // Convert category from ascii to integer by subtracting 48 
  category = line[0] - 48;
  // Remove answer and hint from line
  //strncpy(answer, line[1],MaxSize);
  //strncpy(hint, line[MaxSize+1], HintSize);
/*
cout<<"this is the category: "<<category<<endl;
cout<<"this is the word: "<<answer<<endl;
cout<<"this is the hint: "<<hint<<endl;
*/
}  

