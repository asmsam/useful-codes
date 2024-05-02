//mult_inheritance
#include <iostream>

using namespace std;

class b{
  public :
  int a=1;
  b () {
    cout << "Base called" << endl;
  }
};

class b1 {
  public :
  int a=2;
  b1 () {
    cout << "Base 1 called" << endl;
  }
};

class d : public b1, public b {
  public :
  d () {
    cout << "derived called" << endl;
  }
};

int main()
{
  d D;
  cout << endl << D.b::a;
  int x,y,z;
  x=5;
  y = ++x * x--;
  z = ++y + --y; //at the = sighm what is thefinal value of each variable...
  cout << endl << x << " " << y << " " << z << endl;
  return 0;
}
