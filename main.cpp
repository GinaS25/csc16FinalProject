#include <iostream>
using namespace std;
#include <string>
#include <locale>
#include <fstream>
#include "hangman.h"

/* This is a 1 or 2 Player Hangman Game. Players can save the game and reload it */

int main()
{
  char ch;
  string player1, player2, fileName;
  bool newGame = true;

  cout <<endl<<endl<< "Welcome to"<<endl<<endl;

  cout <<" _    _      __       _    _  _____    _          __       _    _"<<endl;
  cout <<"| |  | |    /  \\    |\\ \\  | ||  ___| |\\ \\  /|    /  \\    |\\ \\  | |"<<endl;
  cout <<"| |__| |   / /\\ \\   | \\ \\ | || |     | \\ \\/ |   / /\\ \\   | \\ \\ | |"<<endl;
  cout <<"|  __  |  / /__\\ \\  | |\\ \\| || | __  | |\\/| |  / /__\\ \\  | |\\ \\| |"<<endl;
  cout <<"| |  | | / /    \\ \\ | | \\ \\ || |_| | | |  | | / /    \\ \\ | | \\ \\ |"<<endl;
  cout <<"|_|  |_|/_/      \\_\\|_|  \\_\\||_____| |_|  |_|/_/      \\_\\|_|  \\_\\|"<<endl;

   cout <<endl<<"Would you like to start a new game or continue playing a saved game?"<<endl;
   cout <<endl<<"Type N for New or S for Saved: ";
   cin >> ch;
   if(toupper(ch) == 'N')
   {
     cout <<endl<<"Enter the name of Player 1: ";
     cin >> player1;
     cout <<endl<<"Enter the name of Player 2: ";
     cin >> player2;
   }
/*
   else
   {
     for(;;)
     {
       //  Get name of saved game
       cout << "Enter the name of the saved game or X to Exit"<<endl;
       cin >> fileName;
       if(toupper(fileName[0]) == 'X')
          break;

 // Read file and process. Handle file not found
       if( !readFile(fileName))
         cout << "File Not Found"<<endl;
       else
         break;
     }
   }
*/
   while(newGame)
   {
//      chessBoard.setupBoard();
//      while (chessBoard.playGame());
      cout <<endl<< "Do you want to play again? (Y or N): ";
      cin >> ch;
      if (toupper(ch) == 'N' )
        newGame = false;
    }



}
