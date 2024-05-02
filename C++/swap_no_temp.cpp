//Swap without temp variable
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

void swapConst(int *a, int *b)
{
    *a = *a+*b;
    *b = *a-*b;
    *a = *a-*b;
    //cout << "*a=" << *a << ", *b=" << *b << endl;
}

int main()
{
    const int a=1;
    const int *a1 = &a;
    const int b=2;
    const int *b1 = &b;
    cout << "a=" << a << ", b=" << b << endl;
    swapConst(const_cast<int*>(a1), const_cast<int*>(b1));
    cout << "*a1=" << *a1 << ", *b1=" << *b1 << endl;
    return 0;
}