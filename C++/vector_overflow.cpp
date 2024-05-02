/*to edit this template :
cd C:\Users\aseemsa\.vscode\extensions\ralfzhang.filetemplate-2.0.4\asset\templates
open cpp.tmpl
*/
#include <iostream>
#include <cstdlib>
#include <vector>

//This program returns 0 0 1 1 1. Vector overflow will never happen. Vector is always initialized with 0 when declared with a size.

using namespace std;

int main()
{
    vector<int> a(2);
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);

    for(int i=0; i<a.size(); i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}