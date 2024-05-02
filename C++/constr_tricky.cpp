#include <iostream>

using namespace std;

class A
{  public:
   explicit A() {cout << "C1" << endl;};       /*explicit : You can only assign values that match the values of the class type.*/
   explicit A(int) {cout << "C2" << endl;};
   explicit A(const char*, int x = 0) {cout << "C3" << endl;};
};

int main() {
    //all legal constructor calls
    A a1;
    
    A a2 = A(1);
    A a3(1);
    A* p = new A(1);
    A a5 = (A)1;
    A a6 = static_cast<A>(1);
    delete p;
    A a4 = A("Venditti");
    return 0;
}