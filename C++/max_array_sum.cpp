#include<iostream>
#include<vector>

using namespace std;

int findMAxSum(std::vector<int> v, int s)
{
  int mx=0, sum=0, t=0, j=0;
  int temp;
  for (int i=0; i<=v.size()-(2*s-1); i++)
  {
    temp=s-1;
    j=i;
    t=0;
    sum=0;
    while(temp!=0)
    {
      temp--;
      sum+=v[j];
      //cout << "v[j]=" << v[j] << ", temp=" << temp << endl;
      j+=2;
    }
    if(temp==0)
    {
      while(j<=(v.size()-1))
      {
        //cout << "v[j]=" << v[j] << endl;
        t=sum+v[j];
        if(mx<t)
        {
          mx=t;
        }
        j++;
      }
    }
  }
  return mx;
}

int main()
{
  int temp=0, max=0;
  bool x=1;
  char c=x;
  std::cout << "c : " << c << '\n';
  std::vector<int> a = {3, 5, -7, 8, 10, 2, 3, 6, -5, 9};
  for (int x=2; x<=(a.size()+1)/2; x++) //the max non adjascent length is alternate, with this epression
  {
    //cout << "x=" << x << endl;
    temp = findMAxSum(a,x);
    if(temp>max)
    {
      max=temp;
    }
  }
  std::cout << max << '\n';
  return 0;
}
