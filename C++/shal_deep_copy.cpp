//shallow copy, deep copy

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

/* 
if the variables of an object have been dynamically allocated then it is required to do a Deep Copy in order to create a copy of the object.

Basics:
Copy Constructor
Foo Obj1(Obj);
or
Foo Obj1 = Obj;
Default assignment operator
Foo Obj2;
Obj2 = Obj1;

-> Manually difined copy constructor creates a new space in heap memory for the new object. Thus, deep copy, which means
creating a copy of original variable, without both having same addresses, uses a manual copy constructor.
-> Default copy constructor copies the !address! of the input variable for dynamically allocated variables. Shallow copy doesn't create a
copy of the variable value, but creates a pointer variable with same address, hence change done to one object reflects in other one.
*/

class Shalc //default copy constructor is created internally, which copies addresses
{
private:
    int * x;
public:
    Shalc(int inp){
        x = new int;
        *x=inp;
    };
    void changeVal(int inp){
        *x = inp;
    }
    void printVal(){
        cout << endl << "Shal Print : " << *x;
    }
    ~Shalc() {delete x;}
};

class Deepc //copy constructor is created manually, address not copied
{
private:
    int * x;
public:
    Deepc(int inp){
        x = new int;
        *x=inp;
    };
    Deepc(Deepc& obj){
        x = new int;
        *x = *(obj.x); /* x = obj.x; <= This will be shallow copy due to = of address instead of value*/
    }
    void changeVal(int inp){
        *x = inp;
    }
    void printVal(){
        cout << endl << "Deep Print : " << *x;
    }
    ~Deepc() {delete x;}
};

int main()
{
    cout << "===Shallow Copy===" << endl;
    Shalc sc1(10);
    Shalc sc2 = sc1;
    sc1.printVal();
    sc2.printVal();
    sc1.changeVal(20);
    sc1.printVal();
    sc2.printVal();
    cout << " <= This also channged" << endl;

    cout << endl << "===Deep Copy===" << endl;
    Deepc dc1(10);
    Deepc dc2 = dc1;
    dc1.printVal();
    dc2.printVal();
    dc1.changeVal(20);
    dc1.printVal();
    dc2.printVal();
    cout << " <= This unchannged" << endl;
    return 0;
}