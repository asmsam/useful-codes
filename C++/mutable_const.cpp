
#include <iostream>
using std::cout;
 
class Test {
public:
  int x;
  mutable int y;
  Test() { x = 4; y = 10; }
};
int main()
{
    const Test t1;
    //t1.x = 1; //error: assignment of member 'Test::x' in read-only object
    t1.y = 8;
    cout << t1.x << ", " << t1.y;
    return 0;
}