/*to edit this template :
cd C:\Users\aseemsa\.vscode\extensions\ralfzhang.filetemplate-2.0.4\asset\templates
open cpp.tmpl
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Banana
{
public:
    Banana(){};
    void eatBanana(){cout << "Banana" << endl;};
    ~Banana();
};

class Mango
{
public:
    Mango(){};
    void eatMango(){cout << "Mango" << endl;};
    ~Mango();
};

int main()
{
    /*const_cast<T>
    - avoid using it. use it only in below cases :
    	1. An externally defined function takes input in non const type whereas the code has const type defined.
    */

    const int a1 = 10;
    const int *b1 = &a1;
    int *d1 = const_cast<int*>(b1);
    *d1 = 15;			//this should give undefined behaviour

    cout << "d1=" << *d1 << endl << "a1=" << a1 << endl;  //but this prints 15 and 10, because (??) the value is replaced by the compiler while optimising the code
						                                //hence we see those values. But those aren't expected -> then why doesn't compiler throw error??

    int a2 = 11;
    const int *b2 = &a2;
    int *d2 = const_cast<int*>(b2);
    *d2 = 16;			//this should give undefined behaviour

    cout << "d2=" << *d2 << endl << "a2=" << a2 << endl; 

//--------------------------------------------
    /*reinterpret_cast<>
    it can perform dangerous conversion due to any pointer to any pointer typecasting

    */
   cout << "reinterprete_cast" << endl;
   Banana *b = new Banana();
   Mango *m = new Mango();
   Banana *newbanana = reinterpret_cast<Banana*>(m);
   newbanana->eatBanana();

    return 0;
}