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

//Friend class
class A{
    int a = 5; //this declaration+initialization is allowed in classes!!!
    //public : //this is optional
    friend class B; //B can access all from A. Basically A says B can access all of me. :P
};
class B //friend class
{
private:
    int b;
public:
    B(){};
    ~B(){};
    int geta(A &x){return x.a;}
};
class C //non friend class
{
private:
    int c;
public:
    C(){};
    ~C(){};
    //int geta(A &x){return x.a;} //ERROR : member "A::a" (declared at line 15) is inaccessible
};

//Friend function
class Box    
{    
    private:    
        int length;    
    public:    
        Box(): length(0) { }    
        friend int printLength(Box); //friend function    
}; 
int printLength(Box b)    
{    
   b.length += 10;    
    return b.length;
} 

int main()
{
    A oba;
    B obb;
    
    //cout << obb.a; //a is private, can't access directly thru main
    cout << obb.geta(oba); //accessing from insude the class is possible, since the scope of a has been extended to class B.
    Box b;    
    cout<<endl<<"Length of box: "<< printLength(b)<<endl; 
    cout<<"Length of box: "<< printLength(b)<<endl;
    return 0;
}