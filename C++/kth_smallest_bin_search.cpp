//https://www.geeksforgeeks.org/kth-smallest-largest-element-in-unsorted-array/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;
 
int count(vector<int>& nums, int& mid)
{
    // function to calculate number of elements less than
    // equal to mid
    int cnt = 0;
 
    for (int i = 0; i < nums.size(); i++)
        if (nums[i] <= mid)
            cnt++;
 
    return cnt;
}
 
int kthSmallest(vector<int> nums, int& k)
{
    int low = INT_MAX;
    int high = INT_MIN;
    // calculate minimum and maximum the array.
    for (int i = 0; i < nums.size(); i++) {
        low = min(low, nums[i]);
        high = max(high, nums[i]);
    }
    // Our answer range lies between minimum and maximum
    // element of the array on which Binary Search is
    // Applied
    while (low < high) {
        int mid = low + (high - low) / 2;
        /*if the count of number of elements in the array
          less than equal to mid is less than k then
          increase the number. Otherwise decrement the
          number and try to find a better answer.
        */
        if (count(nums, mid) < k)
            low = mid + 1;
 
        else
            high = mid;
    }
 
    return low;
}

int main()
{
 
    vector<int> nums{ 1, 4, 5, 3, 19, 3 };
    int k = 3;
 
    // Function call
    cout << "K'th smallest element is "
         << kthSmallest(nums, k) << endl;
    return 0;
}