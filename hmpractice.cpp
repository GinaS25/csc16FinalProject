#include <iostream>
using namespace std;

void printKeyboard(string guess) 
{
 cout<<" -----------------------------------"<<endl;
 string s;
 cout<<"|                                   |"<<endl;
 cout<<"|     ";
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
 cout<<"|     ";
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
 cout<<"|                                   |"<<endl;
 cout<<" -----------------------------------"<<endl;
}

int main()
{
 string guess;
 cout<<"Enter the letters you want to remove"<<endl;
 cin>>guess;
 printKeyboard(guess);
 return 0;
}
