//virtualisation, abstract class, interface related questions
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

class Virtua_all                        //class size is 1 if nothing in it. is 4 if virtual function is there
{
    public:
    Virtua_all(){};
    virtual void doo() = 0;
    virtual void foo() {
        cout << "Base foo" << endl;
    }
    ~Virtua_all();
};

Virtua_all::~Virtua_all(){};

class Dv : public Virtua_all {
    public :
    Dv(){};
    void foo(){
        cout << "Derived foo" << endl;
    }
    void doo(){
        cout << "Derived doo" << endl;
    }
    ~Dv(){};
};

int main()
{
    cout << "sizeof Virtual_all : " << sizeof(Virtua_all) << endl;
    cout << "sizeof Derived : " << sizeof(Dv) << endl;
    Virtua_all * p = new Dv();
    delete p;
    return 0;
}