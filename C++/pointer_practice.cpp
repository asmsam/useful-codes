#include <iostream>
#include <vector>

using namespace std;

/* READ functors (function pointers) here https://www.geeksforgeeks.org/functors-in-cpp/
class increment
{
private:
    int num;
public:
    increment(int n) : num(n) {  }
  
    // This operator overloading enables calling
    // operator function () on objects of increment
    int operator () (int arr_num) const {
        return num + arr_num;
    }
};
  
// Driver code
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int to_add = 5;
  
    transform(arr, arr+n, arr, increment(to_add));

    return 0;
}
*/

void dynamic_array()
{
    int size = 5;
    int * myarr = new int[size]; //int is used as a class here, thus c++
    delete[] myarr; //now myarr is dangling
    myarr = NULL; //now it's null, and safe
}

void mult_dynamic_arr()
{
    const int s1 = 4, s2 = 3;
    cout << "normal matrix" << endl;
    int marr[s1][s2] = {{1,2,3},
                        {4,5,6},
                        {7,8,9},
                        {10,11,12}};
    cout << **marr << endl;
    for(int i=0; i<s1; i++)
    {
        for (int j=0 ;j<s2; j++)
        {
            cout << "marr[" << i << "][" << j << "] = " << *(*(marr+i)+j) << endl; //single dereference will point to address of the row i.e. i. double deference will point to the elements of the row.
        }
    }

    cout << "matrix with pointers" << endl;
    int **mpar = new int *[s1]; //use of multidimentional arrays is just to hold the hooks of other arrays / strings / vectors in each pointer
    for (int i=0; i<s1; i++)
    {
        *(mpar+i) = new int[s2]; //this will store address of a new array starting point //or mpar[j]
    }
    //inserting values
    for(int i=0; i<s1; i++)
    {
        for (int j=0 ;j<s2; j++)
        {
            *(*(mpar+i)+j) = i+j;
        }
    }
    for(int i=0; i<s1; i++)
    {
        for (int j=0 ;j<s2; j++)
        {
            cout << "mpar[" << i << "][" << j << "] = " << *(*(mpar+i)+j) << endl;
        }
    }
    for(int i=0; i<s1; i++)
    {
        for (int j=0 ;j<s2; j++)
        {
            delete [] ((mpar+i)+j); //freeing the double pointer spaces //or marr[j]
        }
    }
    delete [] mpar; //freeing the single pointer
    mpar = NULL;
}

int myfunc()
{
    cout << "Just messin around" << endl;
    return 0;
}

int myfunc1(int x)
{
    cout << "Just messin around" << endl;
    return 0;
}

int * arrayret()
{
    int arr[] = {1,2,3,4};
    return arr;
}

bool isLess(int a, int b) //function signatures have to be the same for single pointer to take up
{
    return a < b;
}

bool isGreater(int a, int b) //function signatures have to be the same for single pointer to take up
{
    return a > b;
}

int genericCompare(int ar[], bool (*isLessGreater)(int, int))
{
    return isLessGreater(ar[0], ar[1]);
}

int main()
{
    //dynamic_array();
    //mult_dynamic_arr();
    /*-------function pointers--------*/
    /*---Meth 1----*/
    //declare the functions
    int (*x)() = myfunc;    //declare function pointer : without any arguments
    int (*y)(int) = myfunc1;//declare function pointer : with arguments - mimic the function's arguments
    int *(*z)() = arrayret; //return array
    //call these functions now
    x();
    y(5);
    int *arrret = z();
    //int *arrret=arrayret();
    cout <<"arrret" << *arrret << endl;
    /*for(int i=0; i<4; i++)
    {
        cout<<*(arrret+i)<<" ";
    }*/
    /*---Meth 2-----*/
    //inline function or Lambda function
    auto lambda = [] (int i) {return i*i;};
    //use of function pointer
    int a[] = {1,2};
    bool ret = genericCompare(a, isLess);
    cout << "genericCompare - isLess? " << ret << endl;
    ret = genericCompare(a, isGreater);
    cout << "genericCompare - isGreater? " << ret << endl;
    return 0;
}

/*
1. const int a;
The “a” is a constant integer.
2. int const a;
same as above
3. const int *a / int const *a;
pointer is modifiable, value is not modifiable
4. int * const a;
pointer is not modifiable, value is modifiable
5. int const * a const;
both are not modifiable
*/