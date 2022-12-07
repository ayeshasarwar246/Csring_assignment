#include <iostream>
using namespace std;

class String
{
	char* cString;

public:


	String();       //default constructor
	String(const char*);           //overloaded constructor for substring
      String(const String&);   //copy constructor
     String(const String&, int, int);  //overloaded constructor
	String(const char*, int);     //overloaded constructor from the sequence
	String(int, char);            //overloaded constructor for fill
    int length();               //return length function
	char at(int);                 //for getting char
	String substr(int, int);      //substring
   friend ostream& operator << (ostream&, const String&);  //for operators
   ~String();       //destructor

   char* regrow(char*, int, char);
   void copyArray(char*, int, char*);




};