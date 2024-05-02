/*This cast is used for handling polymorphism. You only need to use it when you're casting to a derived class. This is exclusively to be used in
inheritence when you cast from base class to derived class.
*/

#include <iostream>

using namespace std;

// Base class declaration
class Base {
    public :
    virtual void print()
    {
        cout << "Base" << endl;
    }
};
  
// Derived Class 1 declaration
class Derived1 : public Base {
    public :
    void print()
    {
        cout << "Derived1" << endl;
    }
};
  
// Derived class 2 declaration
class Derived2 : public Base {
    public :
    void print()
    {
        cout << "Derived2" << endl;
    }
};

int main()
{
    Derived1 d1p;
    int c=0;
    // Base class pointer hold Derived1
    // class object
    Base* bp = dynamic_cast<Base*>(&d1p);
    bp->print();
    // Dynamic casting
    Derived2* d2p = dynamic_cast<Derived2*>(bp);    //this will not return any pointer
    if (d2p == nullptr)
        cout << "d2p null" << endl;

    Derived1* d1p1 = dynamic_cast<Derived1*>(bp);   //this is allowed
    if (d1p1 == nullptr)
        cout << "d1p1 null" << endl;
    
    d1p1->print(); //will print
    //d2p->print();  //will not print
  
    return 0;
}