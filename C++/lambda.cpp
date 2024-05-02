#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

/*
Origins -> Lambda Calculus - calculus of anything for computing using
strings of function lines.
Added in C++ v11.

Lambda function = function lines that are anonymous, disposible, can 
be treated like a temporary variable than a symbol like an actual function.
It is like writing a runnable function, instead of having to write a function.

When to use it - when you may need a functor, use lambda*/

/*generic - 
auto variable = [ _1_ ] ( _2_ ) -> _3_ { _4_ }
1. can contain
    -> a, &b    - a received by value, b by reference
    -> =        - all with value
    -> &        - all with reference
2. argument list
3. optional return type
4. body
*/

/*void for_each_int(vector<int>& a, void(*f)(int))  //Error: no suitable conversion function from "lambda [](int a)->int" to "void (*)(int)" existsC/C++(413)
{
    for(auto x : a) {
        f(x);
    }
}*/

void for_each_int(vector<int>& a, function<void(int&)> f)
{
    for(int i=0; i<a.size(); i++) {
        f(a[i]);
    }
}
int main() {
    vector<int> av = {2,3,6,5,4};

    /*auto var = [] (int a1) { return a1*5; };            //X
    auto var1 = [] (int a) { cout << a << endl; };*/
    //for_each_int(a, var);             //Error: no suitable conversion function from "lambda [](int a)->int" to "void (*)(int)" existsC/C++(413)

    /*for_each_int(av, var);
    for_each_int(av, var1);*/
    for_each_int(av, [&] (int& x) {return x*5;});
    for_each_int(av, [] (int& x) {cout << x << endl;});

    return 0;
}