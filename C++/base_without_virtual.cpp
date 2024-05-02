/*When derived class overloads the methods of base class, the base class methods become hidden.
To make them unhidden in derived class, use the keyword 'using <base class>::<function>' */

#include <iostream>
using namespace std;
  
class Base {
public:
    int fun() { cout << "Base::fun() called"; }
};
  
class Derived : public Base {
public:
    using Base::fun;    //using keyword doesn't require 'virtual' to be used
  
    int fun(char c) // Makes Base::fun() and Base::fun(int )
                    // unhidden
    {
        cout << "Derived::fun(char c) called";
    }
};

/*-----------------------*/

struct A
{
    void AMethod() {cout << "\nclass A AMethod" << endl;}
};

class B : public A
{
    void AMethod() {cout << "\nclass B AMethod" << endl;} //Hides A::AMethod
};

// Driver Code
int main()
{
    Derived d;
    d.fun(); // Works fine now
    /*-----------------------*/
    B myB;
    //myB.AMethod(); //Error: AMethod is private
    static_cast<A*>(&myB)->AMethod(); //Ok
    
    return 0;
}