#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class A {
    public :
    int x,y;
    A(int a, int b): x(a), y(b) {};
    ~A() {};
    bool operator <(const A& rhs) const
    {
        return this->y < rhs.y;
    }
};

int main()
{
    /*std::vector<pair<int, int>>vp = {{1,1},{2,3}} ;
    std::vector<pair<int, int>>::iterator it = std::find(vp.begin(), vp.end(), 2);
    cout << it->first << it->second;*/
    
    std::map<A,int> trial;
    A a1(1,1);
    A a2(2,2);
    trial.insert(make_pair(a1,1));
    trial.insert(make_pair(a2,2));
    
    std::map<A, int>::iterator beg = trial.begin();
    cout << (beg++)->first.y << endl;
    cout << beg->first.y << endl;
    return 0;
}