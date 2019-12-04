#include <iostream>
#include <string>
#include <locale>
//#include "Chess.h"
using namespace std;

bool readFile(string str);
bool writeFile(string str);

/* This is a 2 Player Chess Game. Players can save the game and reload it. */

int main()
{
 //  Board chessBoard;
   string str, player1White, player2Black, fileName;
   bool playgame = true;
   cout << "   _____ _    _ ______  _____ _____ \n  / ____| |  | |  ____|/ ____/ ____| \n | |    | |__| | |__  | (___| (___  \n | |    |  __  |  __|  \\___  \\___ \\ \n | |____| |  | | |____ ____) |___) | \n  \\_____|_|  |_|______|_____/_____/ \n" << endl;
   cout << "Welcome to Chess"<<endl<<endl;
   cout << "Would you like to start a new game or continue playing a saved game?"<<endl;
   cout << "Type N for New or S for Saved: ";
   cin >> str;
   if(toupper(str[0]) == 'N')
   {
     cout << "Enter the name of Player 1 (White Chess Piece):";
     cin >> player1White;
     cout << endl<<endl<<"Enter the name of Player 2 (Black Chess Piece):" << endl;
     cin >> player2Black;
   }
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
/*
   while(playgame)
   {
      chessBoard.setupBoard();
      while (chessBoard.playGame());
      cout << "Do you want to play again? (Y or N)";
      cin >> str;
      if (toupper(str) != "Y" )
        playgame = false;
    }
*/
   return 0;
}

bool readFile(string fileName)
{
  // read saved game
 return 0;
}

bool writeFile(string fileName)
{
  // save game
  return 0;
}
