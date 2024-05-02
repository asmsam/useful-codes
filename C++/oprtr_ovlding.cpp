#include <iostream>
#include <string>
#include <map>
using namespace std;

//constructors of each type

class B{
    public :
        int a;
        int b;
        B():a(1),b(1){};
};

class A{
    private :
        int a;
    public :
        A() {};
        A(B& copyClass)
        {
            cout << "b copy a" << endl;
            a = copyClass.a;
        };
        A(A& copyA)
        {
            cout << "a copy a" << endl;
            a = copyA.a;
        }
        A& operator = (A& Aeq)
        {
            cout << "Equating ";
            this->a = Aeq.a;
            return *this;
        }
        A operator ++(int){
            cout << "inside post ";
            A temp(*this);
            ++(*this);
            return temp;
        };
        A operator ++(){
            a++;
            return *this;
        };
        A& operator+= (A& Aobj)
        {
            this->a=this->a + Aobj.a;
            return *this;
        }
        int getA(){return a;}
};

int main ()
{
    B myB;
    cout << myB.a << " " << myB.b << endl;
    A myA(myB);
    cout << "copy constr : " << myA.getA() << endl;
    myA++;
    A a1 = myA;
    cout << "post : " << a1.getA() << " since the object didn't receive the incremented value imm" << endl;
    ++myA;
    A a2 = myA; 
    cout << "pre : " << a2.getA() << " since the object received the incremented value imm" << endl;
    A a3 = a1; //copy constructor called
    cout << "Equaled " << a3.getA() << " since the object received the incremented value imm" << endl;
    a2 += a1;
    cout << "Operator += " << a2.getA() << endl;
    return 0;
}

