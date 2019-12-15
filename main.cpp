#include <iostream>
using namespace std;
#include <locale>

/* prototypes */
bool playHangman();
bool readFile();

/* This is a Hangman Game */

int main()
{
  // Play hangman until user exits
  for(;;)
  {
    if(readFile())
      return 0;
    if(playHangman())
      cout<<endl<<"              Congratulations! You won!!! ";
    else
      cout<<endl<<"                      Game Over";

    cout<<endl<<endl<< "        Do you want to play again? Enter 'Y' for Yes: ";
    char ch;
    cin>>ch;
    if(toupper(ch)!='Y')
      break;
  }
  return 0;
}
