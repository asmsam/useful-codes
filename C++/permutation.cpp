//permutations with rotation
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

vector<vector<int>> perm;

void permutations(vector<int> a, int i, int n)
{
    // last swap has been done. Now add the permutation to the list
    if (i == n - 1)
    {
        perm.push_back(a);
        return;
    }
 
    // process each character of the remaining string
    for (int j = i; j < n; j++)
    {
        // swap character at index `i` with the current character
        swap(a[i], a[j]);        // STL `swap()` used
 
        // recur for substring `a[i+1, n-1]`
        permutations(a, i + 1, n);
 
        // backtrack (restore the string to its original state)
        swap(a[i], a[j]);
    }
}

int main()
{
    vector<int> a = {5 ,6, 7, 8};

    //int num = permut(a);

    permutations(a, 0, a.size());

    for(int i=0; i<perm.size(); i++)
    {
        for(int j=0; j<perm[i].size(); j++)
        {
            cout << perm[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}