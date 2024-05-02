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

int main()
{
    /* Minimisation based on number of iterations -
        if rotate is > half the size, rotate it left
        if rotate is < half the size, rotate usual, right
    */
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 5;
    int ns = nums.size();
    if(k==0 || ns==1){
            return 0;
    }
    
    k=k%ns;

    int x = ns-k;

    if(k>ns/2) //rorate anti clockwise
    {
        cout << "Rotate invoke" << endl;
        std::vector<int>::iterator it = nums.begin() + x;
        std::rotate(nums.begin(), it, nums.end());
    }
    else {
        cout << "Rotate not invoke" << endl;
        for(int i=ns; i>x;i--)
        {
            int t = nums[ns-1];
            //nums.erase(nums.begin());
            nums.pop_back();
            nums.emplace(nums.begin(), t);
            cout << "added " << nums[0] << " at beginning" << endl;
        }
    }

    for(int i=0; i<ns;i++)
    {
        cout << nums[i] << ",";
    }    
    return 0;
}