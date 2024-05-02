/*to edit this template :
cd C:\Users\aseemsa\.vscode\extensions\ralfzhang.filetemplate-2.0.4\asset\templates
open cpp.tmpl
*/

/* Tricky and important learnings of OOP
1. Creating two objects and holding a count per object that increments each time constructor is called
    - Lesson -> each object will retain whatever the value it was created with. Break down the procedure to understand
    
2. Static class declaration
    - Lesson -> The reason for this is simple, static members are only declared in a class declaration, not defined. They must be explicitly defined outside the class using the scope resolution operator. 
    if X x = y.getX(); with current setup is run, it will give error Compilaion Error: undefined reference to `Y::x'
3. Using = for assigning value to the only data member of the class, if a parameterized constructor with only one argument is present is that data member.
4. What if & is not used in copy constructor?
5. static casting base pointer to derived type to call a derived method using base pointer.
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

// 1.
class A{
    int count=0;
    public :
    A(){
        count++;
        cout << "A constructor, count = " << count << endl;
    };
    ~A()
    {
        cout << "A distructor, count = " << count << endl;
    }
};
// 2.
class X
{
public:
    X() { cout << "X's Constructor Called " << endl;  }
};
class Y
{
    static X x;                                             //Y is a wrapper arount X. Just that x is declared static, so it is object independent
public:
    Y() { cout << "Y's Constructor Called " << endl; }
    X getX(){return x;}
};
int l2()
{
    Y y;
    X x = y.getX(); //X's constructor is not called.
    return 0;
}

// 3.
class student
{
    int marks;
    public:
    student(){};
    student(int x)
    { 
         marks=x; 
    }
    void printMarks()
    {
        cout << "marks = " << marks << endl;
    }
};

//4.
class Foo
{
private:
    int x;
public:
    Foo(Foo& cpFoo){x=cpFoo.x;}
    ~Foo();
};
class Doo
{
private:
    int x;
public:
    //Doo(Doo d = new Doo()){} //https://stackoverflow.com/questions/21743301/c-incomplete-type-not-allowed-error-accessing-class-reference-information-c
    //Doo(Doo cpDoo){}; //Error : copy constructor for class "Doo" may not have a parameter of type "Doo"
    Doo(){};
    ~Doo();
};

//5.
class A {
    public:
    int a;
    void foo() {
        cout << "in base foo" << endl;
    }
};

class B : public A {
    public:
    int a;
    void foo() {
        cout << "in derived foo" << endl;
    }
};

int main()
{
    //1.
    cout << "Ex 1:-----------------" << endl;
    A a[2];

    //2.
    cout << "Ex 2:-----------------" << endl;
    l2();

    //3.
    cout << "Ex 3:-----------------" << endl;
    student s1(100);
    s1.printMarks();
    student s2;
    s2.printMarks();
    student s3=100;  //<-- This will assign value 100 to the int member of class i.e. marks
    s3.printMarks();

    //4.
    cout << "Ex 4:-----------------" << endl;
    cout << "If copy Constructor is defined without &, Bellow error message is thrown" << endl << "copy constructor for class " << "Doo" << " may not have a parameter of type " << "Doo" << endl;

    //5.
    cout << "Ex 5:-----------------" << endl;
    A *a;
    a->foo();
    static_cast<B*>(a)->foo();      //1st way
    auto x = (B*)(a);               //2nd way
    x->foo();

    cout << "Done:-----------------" << endl;
    return 0;
}