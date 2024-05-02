#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility> //for pair
#include <memory> //for allocator
#include <list>

using namespace std;

/*template <typename T>
T my_find_end(T::iterator i1, T::iterator i2, T::iterator i3, T::iterator i4)
{
    bool flag=0;
    T::iterator i,j, temp;
    j= i3;
    for (i = i1; i<i2; i++)
    {
        if(*i==*j)
        {
            temp = i;
            for (j = i3+1; j<i4; j++)
            {
                if(*temp == *j)
                {
                    flag=1;
                }
                else{
                    flag=0;
                    break;
                }
            }
            if (temp)
            {
                return *j;
            }
        }
    }
    return -1;
}

void my_find_end_test()
{
    string c = "abhgyab";
    string d = "ab";
    std::string::iterator it1 = my_find_end(c.begin(),c.end(), d.begin(), d.end());
    cout << "my_find_end found : " << *it1 << endl;
}*/

template <class myIterator, class T, class U> //it's like declaration of datatypes you're going to use in the function return type and parameters
myIterator get_negative_for(myIterator first, myIterator last, T val,U lambda) //pass by ref or pass by pointer
{
    while(first != last)
    {
        if(*first == val)
        {
            //(*first)*=(-1);
            *first = lambda(*first);
        }
        first++;
    }
    return first;
}

void get_negative_for_test()
{
    cout << endl << "get_negative_for" << endl;
    std::vector<int> v{ 5, 3, -1, 9, 4 };
    auto lambda = [] (int x) {return x * (-1);}; //x is passed as value, so lambda should be used with * inside the template
    vector<int>::iterator it = get_negative_for(v.begin(), v.end(), 4, lambda);
    int x=0;
    for(vector<int>::iterator i=v.begin(); i != v.end(); i++)
    {
        cout << "v_neg[" << x << "]=" << *i << endl;
        x++;
    }

}

void all_of_test()
{
    cout << "all_of" << endl;
    std::vector<int> v{ 5, 3, -1, 9, 4 };
    auto lambda = [](int i) { return i > 1; };
    bool allGreaterThanOne = std::all_of(v.begin(), v.end(), lambda);
    cout << allGreaterThanOne << endl;
    return;
}

void any_of_test()
{
    cout << "any_of" << endl;
    std::vector<int> v{ 5, 3, 7, 9, 4 };
    auto lambda = [](int i) { return i > 8; };
    bool anyGreaterThanEight = std::any_of(v.begin(), v.end(), lambda);
    cout << anyGreaterThanEight << endl;
    return;
}

void none_of_test()
{
    cout << "none_of" << endl;
    std::vector<int> v{ 5, 3, 7, 9, 4 };
    auto lambda = [](int i) { return i > 10; };
    bool noneGreaterThanTen = std::none_of(v.begin(), v.end(), lambda);
    cout << noneGreaterThanTen << endl;
    return;
}

void for_each_test()
{
    cout << "for_each" << endl;
    std::vector<int> v{ 5, 3, 7, 9, 4 };
    auto lambda = [] (int i) {cout << i << endl;};
    cout << "Test lambda ";
    lambda(5);
    std::for_each(v.begin(), v.end(), lambda);
    return;
}

void find_test()
{
    cout << "find" << endl;
    std::vector<int> v{ 5, 3, 7, 9, 4 };
    std::vector<int>::iterator it = std::find(v.begin(), v.end(), 3);
    cout << *it << endl;
}

void find_end()
{
    cout << "find_end" << endl;
    vector <char> a{'a','b','h','g','y','a','b'};   //works with vector of chars
    vector <char> b{'a','b'};
    string c = "abhgyab";                           //works with string
    string d = "ab";
    std::vector<char>::iterator it1 = std::find_end(a.begin(),a.end(), b.begin(), b.end());
    std::string::iterator it2 = std::find_end(c.begin(),c.end(), d.begin(), d.end());
    cout << "vector of chars : " << *it1 << endl;
    cout << "string : " << *it2 << endl;
}

void mismatch_test()
{
    cout << "mismatch ";
    vector<int>a = {1,2,7,4};
    vector<int>b = {1,2,3,4};
    pair <vector<int>::iterator, vector<int>::iterator> p = mismatch(a.begin(), a.end(), b.begin(),b.end());
    cout << "so, " << *(p).first << " " << *(p).second;
}

void equal_test()
{
    cout << endl << "equal ";
    vector<int>a = {1,2,7,4};
    vector<int>b = {1,2,3,4};
    bool isEq = equal(a.begin(), a.end(), b.begin());
    cout << isEq << endl;
}

void copy_backward_test()
{
    cout << "copy_backward_test" << endl;
    std::vector<int> v1{1,2,3,4};
    std::vector<int> v2{1,3};
    std::vector<int> v3(2);
    std::vector<int>::iterator it = std::copy_backward(v1.begin(), v1.end(), v2.end());
    int x=0;
    for (it = v2.begin(); it != v2.end(); it++)
    {
        cout << "v2[" << x << "]=" << *it << " ";
        x++;
    }
    cout << "<- allows overwriting existing vector with given size" <<endl;

    std::vector<int>::iterator it1 = std::copy_backward(v1.begin(), v1.end(), v3.end());
    int y=0;
    for (it1 = v3.begin(); it1 != v3.end(); it1++)
    {
        cout << "v3[" << y << "]=" << *it1 << " ";
        y++;
    }
    return;
}

void iter_swap_test()
{
    cout << "iter_swap" << endl;
    vector <int> v = {1,2,3,4};
    vector <int>::iterator i1 = v.begin();
    vector <int>::iterator i2 = v.begin()+2;
    iter_swap(i1, i2);
    int x=0;
    for(vector<int>::iterator i=v.begin(); i != v.end(); i++)
    {
        cout << "v[" << x << "]=" << *i << endl;
        x++;
    }
}

void allocator_test()
{
    // allocator for integer values
    allocator<int> myAllocator;
  
    // allocate space for five ints
    int* arr = myAllocator.allocate(5);
  
    // construct arr[0] and arr[3]
    myAllocator.construct(arr, 100);
    arr[3] = 10;
  
    cout << arr[3] << endl;
    cout << arr[0] << endl;
  
    // deallocate space for five ints
    myAllocator.deallocate(arr, 5);

    /*
    Member functions associated with std::allocator() :
    1. address: It is used for obtaining the address of an object although it is removed in C++20.
    2. construct: It is used to construct an object.It is also removed in C++20.
    3. destroy: It is used to destruct an object in allocated storage.It is also removed in C++20.
    4. max_size: It returns the largest supported allocation size.It is deprecated in C++17 and removed in C++20.
    5. allocate: Used for allocation of memory.
    6. deallocate: Used for deallocation of memory.
    */
    return;
}

void allocator_example()
{
    std::list<int> mylist;
    int * p;

    // allocate an array of 5 elements using mylist's allocator:
    p=mylist.get_allocator().allocate(5);

    // assign some values to array
    for (int i=0; i<5; ++i) p[i]=i;

    std::cout << "The allocated array contains:";
    for (int i=0; i<5; ++i) std::cout << ' ' << p[i];
    std::cout << '\n';

    mylist.get_allocator().deallocate(p,5);

    return;
}

void transform_test()
{
    cout << endl << "transform\n";
    std::vector<int> v1{ 1, 2, 3 };
    std::vector<int> v2{ 4, 5, 6 };
    std::vector<int> res(3);
    auto lambdaMultiply = [](int i, int j) { return i * j; };
    std::vector<int>::iterator it = std::transform(v1.begin(), v1.end(), v2.begin(), res.begin(), lambdaMultiply);
    int x=0;
    for(vector<int>::iterator i=res.begin(); i != res.end(); i++)
    {
        cout << "res[" << x << "]=" << *i << endl;
        x++;
    }
}

void unique_copy_test()
{
    cout << endl << "unique_copy\n";
    std::vector<int> v{ 1, 1, 2, 3, 3 };
    std::vector<int> res(3);
    unique_copy(v.begin(), v.end(), res.begin());
    int x=0;
    for(vector<int>::iterator i=res.begin(); i != res.end(); i++)
    {
        cout << "res[" << x << "]=" << *i << endl;
        x++;
    }
}

void rotate_test()
{
    std::vector<int> v{ 1, 2, 3, 4 };
    std::vector<int>::iterator it = v.begin() + 2; // Points to 3
    std::rotate(v.begin(), it, v.end());
    int x=0;
    for(vector<int>::iterator i=v.begin(); i != v.end(); i++)
    {
        cout << "v_rot[" << x << "]=" << *i << endl;
        x++;
    }
}


//to use iterator in reverse. use vector<int>::reverse_iterator rit = v.rbegin() etc.

int main()
{
    all_of_test();
    any_of_test();
    for_each_test();
    find_test();
    //find_first_of - same as find_end, but will give first occurance
    //find_if - if the lambda function is satisfied, returns iterator at the 1st satisfying
    //find_if_not - iterator at the first unsatisfying
    //find_end - find the last occurence of a sequence in that range
    find_end();
    //my_find_end_test();
    mismatch_test();
    equal_test();
    //-----two ways to declare array / string----
    char str[] = "my string";
    const char * str1 = "my string";
    //-------------------------------------------
    //copy_if - useful to filter out based on certain condition and copy to another
    /*these take only 3 pointers : v1.begin, v1.end v2.begin
    - mismatch
    - equal
    - is_permutation
    - copy
    - copy_if
    - copy_backward - only change : v2.end()
    - move
    - swap_ranges
    - transform - much like for_each, but add the modified values to a new vector
    - replace_copy
    - replacecopyif
    - unique_copy
    - reverse_copy
    - rotate_copy
    make sure you know how to use 'at' pointer instead of 'begin' and 'end'*/
    // unique, remove and remove_if are problematic, since they don't actually remove, but assign another element at the pos of removed one that is given in input or follows lambda condition.
    //copy_backward_test();
    iter_swap_test();
    /*allocator*/
    allocator_test(); //allocator is a part of all the containers. getallocator is used to get the pointer, and allocate / deallocate to assign/ unassign memmory.
    allocator_example();
    transform_test(); //<functional> library functions are often used with this.
    //myown
    get_negative_for_test();
    unique_copy_test();
    rotate_test();
    //merge is nice

    /*to do :
    - dynamic_cast
    - binary_tree
    - 
    */

    return 0;
}