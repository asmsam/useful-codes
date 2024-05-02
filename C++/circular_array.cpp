#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> A={1,2,3,4,5};
  int x=2;
  int l=A.size();
  /*static char __NUMERIC_NULL[9]="ÀÀÀÀ";
  long int y='À';
  std::cout << y << '\n';
  int a='À';
  cout << a;*/
  for(int i=0; i<l; i++)
  {
    if(i+x==l)
    {
      x+=1;
      x*=-1;
    }
    cout << A[i+x] << endl;
  }
  return 0;
}
