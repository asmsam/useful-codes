/*to edit this template :
cd C:\Users\aseemsa\.vscode\extensions\ralfzhang.filetemplate-2.0.4\asset\templates
open cpp.tmpl
*/


/*All the coding quesions asked in intvs that I couldn't get right at some point ',or didn't understand*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

/*struct vs class*/
struct A{
    int a;
    A(){a = 5; cout << "overloaded A constr" << endl;};             //overloading default constructor - WORKS
    virtual void foo()=0;                                           //using virtual functions - WORKS
    ~A(){};                                                         //using distructors - WORKS
};
struct C{
    int x = 1;
    char y = 'h';
    friend struct B;                                                //using friend keyword - WORKS
};
struct B : public A {
    B(){};
    void foo(){
        cout << "Inside foo of struct B" << endl;
    }
    int getx(C &c){return c.x;}
    char gety(C &c){return c.y;}
    ~B(){};
};

/*copy constructor & ampersand */
class Test{
	public :
	int a;
	Test() : a(0) {cout << "Default Constructor" << endl;};

	Test(const Test& Tobj1)
	{
	    cout << "Copy Constr" << endl;
		a = Tobj1.a;
	}

    /*Test(Test Tobj2) //copy constructor for class "Test" may not have a parameter of type "Test"
	{
	    cout << "Copy Constr" << endl;
		a = Tobj2.a;
	}*/

	Test& operator = (const Test& Tobj){
	    cout << "assignment operator" << endl;
		this->a = Tobj.a;
		return *this;
	}
};

/*use object as key in map*/
class mapObj
{
public:
    int x;
    //char y;
    mapObj();
    mapObj(int a, char b);
    bool operator < (mapObj& mob)
    {
        return (this->x < mob.x) ? 1 : 0;
    }
    ~mapObj();
};

mapObj::mapObj()
{
    x=0;
    //y='\0';
}

mapObj::mapObj(int a, char b)
{
    x=a;
    //y=b;
}

mapObj::~mapObj(){}


int main()
{
    /*vector with elements vs array of vectors */
    /*vector<int> x = {1,2,3,4,5};
    vector<int> a[20];      //array of vectors
    int ar[6];              //array of integers
    cout << "sizeof ar = " << sizeof(ar) << endl;
    cout << "sizeof a = " << sizeof(a) << endl;
    cout << "sizeof x = " << sizeof(x) << endl;

    a[1].push_back(1);
    a[2].push_back(1);
    a[1].push_back(2);
    a[2].push_back(2);
    a[2].push_back(3);
    for(int i=0; i<max(a[1].size(), a[2].size()); i++)
    {
        cout << "a[1][" << i << "]=" << a[1][i] << endl;
        cout << "a[2][" << i << "]=" << a[2][i] << endl;
    }*/
    
    /*struct vs class
        - They say the only difference is by default, struct declares the members to public and class to private.
        - Other differences -
            1. struct doesn't have protected members. It doesn't have access specifiers itself.
            2. ---
    */
    {
    B bs;
    A *as = &bs;
    C c;
    cout << "C members = " << c.x << ", " << c.y << endl;
    as->foo();
    cout << "C members via b = " << bs.getx(c) << ", " << bs.gety(c) << endl;
    }

    /*to use/not to use the '&' in copy contructor or assignment operator
        When & is removed, we are passing the object by value. Every time for pass by value, we make a copy of
        original variable / object.
        Here we'll be making a copy, by using the copy constructor. But it has not yet beem created !!!
        Hence -
        When not used, error is thrown - "Copy constructor of class A may not have parameter of type A"
    */
    {//copy constr
	Test t1;
    t1.a = 10;
	Test t2(t1);
	Test t3 = t2;
	//equal assign operator
	Test t5;
	t1.a = 5;
	t5 = t1;
	cout << t5.a; //5
    }
    /*Deep copy and Shallow copy - in the shal_deep_copy file */

    /*const vs constexpr
    constexpr, added in v11, is a function that is not inline but can be executed and the values of each variable can be determined
    at compiile time*/
    
    /* Diamong problem - in the file oop_basic */

    /*use object as key in map*/
    {
    mapObj mo1(1,'c');
    mapObj mo2(2,'c');

    cout << endl << "The operator '<' is used by the map to distinguish the keys. It can do it only with premitive data-types. Simple operator overloading will not cause maps to pick it." << endl << "mo1 < mo2 ? -> " << (mo1 < mo2) << endl;
    
    map <mapObj, string> mkstr; //this step is allowed
    //mkstr.insert(make_pair(mo1, "string1")); // error: no match for 'operator<' (operand types are 'const mapObj' and 'const mapObj')  386 |       { return __x < __y; }
    //mkstr.insert(make_pair(mo2, "string2")); //won't even reach here.
    }

    /*lambda functions and their use in function*/
    return 0;
}