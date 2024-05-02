//substring efficient
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

int isSubstr(string a, string b)
{
    cout << "Find " << b << " inside " << a << endl;
    int i,j=0, tempi=-1;
    for(i=0; i<a.size(); i++){
        cout << "i=" << i << ", j=" << j << endl;
        if(a[i] == b[j])
        {
            cout << "Matched " << a[i] << " and " << b[j] << endl;
            if(tempi == -1)
            {
                tempi = i;
            }
            if(j == (b.size()-1))
            {
                return tempi;
            }
            j++;
            continue;
        }
        if(a[i] != b[j] && j>0)
        {
            i-=j;
            j=0;
            tempi=-1;
        }
    }
    return -1;
}

int main()
{
    string s = "abxabcabcaby";//"abcbcglx";
    string tf = "abcaby";//"bcgl";
    int pos = isSubstr(s,tf);
    if(pos >=0 )
    {
        cout << "Substring found at position " << pos+1 << endl; 
    }
    else {
        cout << "Not a Substring" << endl;
    }
    return 0;
}