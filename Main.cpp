#include <iostream>
#include "String.h"
using namespace std;

int main()
{
    String s0("initial string");
   
    String s1;
    String s2(s0);
    String s3(s0, 8, 3);
    String s4("A character sequence");
    String s5("other character sequence", 12);
    String s6a(10, 'x');
    String s6b(10, 42);     

    cout << "s1: " << s1 << "\ns2: " << s2 << "\ns3: " << s3
        << "\ns4: " << s4 << "\ns5: " << s5 << "\ns6a: " << s6a
        << "\ns6b: " << s6b << '\n';

    String str("Test string");
    String str2 = str.substr(3, 5); 
    cout << "the value in str is: " << str << endl;
    cout << "the size of str is: " << str.length() << "\n";
    cout << "char at 5th location: " << str.at(5) << "\n";
    cout << "char at 3nd location: " << str.at(3) << "\n";
    cout << "substring: " << str2 << "\n";

	system("pause");
    return 0;
}
