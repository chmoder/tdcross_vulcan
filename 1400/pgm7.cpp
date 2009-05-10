//Name          :Thomas Cross
//Class         :1400009
//Program #     :pgm1
//Due Date      :10.23.08
//
//Honor Pledge  On my honor as a student of the University of Nebraska at Omaha,
// I have neither given nor recieved unauthorized help on this homework
// assignment.
//
//Signed1: Thomas Cross
//Signed2: 1337
//Signed3: tom.bz2@gmail.com

//Partners  :List the full names, CIST 1400 section and e-mail addresses

//

#include <iostream.h>

int main () 
{ char letter;
cout<<"Please enter a charecter for me to translate to morris code:";
cin>>letter;
switch (letter)
{ 
  case 'A': case 'a': cout<<".-\n"; break;
  case 'B': case 'b': cout<<"...\n"; break;
  case 'C': case 'c': cout<<"-.-.\n"; break;
  case 'D': case 'd': cout<<"-..\n"; break;
  case 'E': case 'e': cout<<".\n"; break;
  case 'F': case 'f': cout<<"..-.\n"; break;
  case 'G': case 'g': cout<<"--.\n"; break;
  case 'H': case 'h': cout<<"....\n"; break;
  case 'I': case 'i': cout<<"..\n"; break;
  case 'J': case 'j': cout<<".---\n"; break;
  case 'K': case 'k': cout<<"-.-\n"; break;
  case 'L': case 'l': cout<<".-..\n"; break;
  case 'M': case 'm': cout<<"--\n"; break;
  case 'N': case 'n': cout<<"-.\n"; break;
  case 'O': case 'o': cout<<"---\n"; break;
  case 'P': case 'p': cout<<".--.\n"; break;
  case 'Q': case 'q': cout<<"--.-\n"; break;
  case 'R': case 'r': cout<<".-.\n"; break;
  case 'S': case 's': cout<<".-.\n"; break;
  case 'T': case 't': cout<<"-\n"; break;
  case 'U': case 'u': cout<<"..-\n"; break;
  case 'V': case 'v': cout<<"...-\n"; break;
  case 'W': case 'w': cout<<".--\n"; break;
  case 'X': case 'x': cout<<"-..-\n"; break;
  case 'Y': case 'y': cout<<"-.--\n"; break;
  case 'Z': case 'z': cout<<"--..\n"; break;
  case '1': cout<<".----\n"; break;
  case '2': cout<<"..---\n"; break;
  case '3': cout<<"...--\n"; break;
  case '4': cout<<"....-\n"; break;
  case '5': cout<<".....\n"; break;
  case '6': cout<<"-....\n"; break;
  case '7': cout<<"--...\n"; break;
  case '8': cout<<"---..\n"; break;
  case '9': cout<<"----.\n"; break;
  case '0': cout<<"-----\n"; break;
  case '@': cout<<".--.-.\n"; break;
  case ',': cout<<"--..--\n"; break;
default: cout<<"Enter a letter, number (0-9), or '@' or ','\n";
}
return 0;
}
