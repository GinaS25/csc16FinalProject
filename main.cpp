#include <iostream>
using namespace std;
#include <locale>

/* prototypes */
bool playHangman();
bool readAnsFile();

/* This is a Hangman Game */

int main()
{
  // Play hangman until user exits
  for(;;)
  {
    if(readAnsFile())
      return 0;
    if(playHangman())
      cout<<endl<<"                Congratulations! You won!!! ";
    else
      cout<<endl<<"                        Game Over";

    cout<<endl<<endl<<endl<< "        Do you want to play again? Enter 'Y' for Yes: ";
    char ch;
    cin>>ch;
    if(toupper(ch)!='Y')
      break;
  }
  return 0;
}
