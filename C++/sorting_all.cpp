//insertion sort
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//as we increment i, go on sorting the elements till then. If value at i is lesser than any behind it, just
//pick it and put it where it belongs. This is in assumption that elements till i will be sorted.
vector <int> insert_sort(vector <int> a)
{
    int i,j,t;
    for(i=0; i<a.size(); i++)
    {
        j=i-1;
        t=a[i];
        while(j>=0)
        {
            if(a[j] > t)
            {
                a[j+1] = a[j];
                a[j]=t;
            }
            j--;
        }
    }
    return a;
}

//go from start to end by putting the min element at the start of distance from i to end.
vector <int> select_sort(vector <int> a)
{
    for(vector<int>::iterator i=a.begin(); i != a.end(); i++)
    {
        vector<int>::iterator it1 = min_element(i, a.end());
        if(*it1 != *i)
        {
            swap(*it1,*i);
            // or iter_swap(it1,i);
        }
    }
    return a;
}

void merge(vector<int> &a, int l, int m, int r)
{
    int len1 = m - l + 1;
    int len2 = r - m;
    vector<int> left;
    vector<int> right;
    int x=0, y=0, z=l;
    //copy to left and right
    while(x < len1)
    {
        left.push_back(a[l+x]);
        x++;
    }
    while(y < len2)
    {
        right.push_back(a[m + 1 + y]);
        y++;
    }
    //combine by comparing each
    x=0;
    y=0;
    while(x < len1 && y < len2)
    {
        if(left[x] < right[y])
        {
            a[z] = left[x];
            x++;
        }
        else{
            a[z] = right[y];
            y++;
        }
        z++;
    }
    //combine the leftovers, first from left, then from right
    while(x < len1)
    {
        a[z] = left[x];
        x++;
        z++;
    }
    while(y < len2)
    {
        a[z] = right[y];
        y++;
        z++; 
    }
}
void merge_routine(vector<int> &a, int const l, int const r)
{
    if(l>=r)
    {
        return;
    }
    auto m =  l + (r-l)/2;
    //cout << endl << "a[l]=" << a[l] << " a[m]=" << a[m] << " a[r]=" << a[r] << endl;
    merge_routine(a, l, m);
    merge_routine(a, m+1, r);
    merge(a, l, m, r);
    /*cout << endl << "temp merged array : " << endl;
    for(int i=0; i<a.size(); i++)
    {
        cout << a[i] << " ";
    }*/
}

int partition_q(vector <int> &a, int l, int r)
{
    int piv = a[r];
    int i=l-1;

    for(int j=l; j<r; j++)
    {
        if(a[j] < piv)
        {                       //increment i when an element less than pivot is found. i won't be less than
            i++;                //pivote because j has already passed through it.
            swap(a[i], a[j]);   //swapping is done in the anticipation that after line 121 is executed, the
        }                       //pivote will come right at the middle of digits smaller and larger than it.
    }
    swap(a[i+1], a[r]);
    return i+1;
}
void quick_sort(vector <int> &a, int l, int r)
{
    //two types : single direction(i++, j++), as in geeksforgeeks and bidirectional (i++ and j--) as in the video
    //1]
    if(l<r) //meaning if there are atleast 2 elements
    {
        int piv = partition_q(a, l, r);

        quick_sort(a, l, piv-1);
        quick_sort(a, piv+1, r);
    }
}


int main()
{
    vector<int> a = {5, 2, 1, 9, 4, 3};
    vector<int> b(a);
    vector<int> c(a);
    vector<int> d(a);
    vector<int> e(a);
    b = insert_sort(a);
    int i;
    int sz = a.size();
    cout << "insertion :" << endl;
    for(i=0; i<sz; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl << "selection :" << endl;
    c = select_sort(a);
    for(i=0; i<sz; i++)
    {
        cout << c[i] << " ";
    }

    cout << endl << "merging :" << endl;
    merge_routine(d, 0, d.size()-1);
    for(i=0; i<sz; i++)
    {
        cout << d[i] << " ";
    }

    cout << endl << "quick sorting :" << endl;
    quick_sort(e, 0, e.size()-1);
    for(i=0; i<sz; i++)
    {
        cout << e[i] << " ";
    }
    return 0;
}