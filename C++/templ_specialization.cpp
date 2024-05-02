#include <iostream>
using namespace std;

/* https://www.geeksforgeeks.org/template-specialization-c/ */

/* Template Specialization - function / Class
    - When we write any template based function or class, compiler creates a copy of that function/class if it is used for a new
    patameter type or new set of parameter types(in case of multiple template arguments).
    - Compiler first checks with the specialized version, then the main template. Most specialized version is checked by matching
    the defined parameter(s) in the definition with the data type(s) passed in multiple calls of the function or class. 
*/

/* Function T-specialization */
// 1.
template <class T>
void fun(T a)
{
   cout << "The main template fun(): "
        << a << endl;
}
//T-sp'd for int->
template<>
void fun<int>(int a)
{
    cout << "Specialized Template for int type: "
         << a << endl;
}

// 2. A generic sort function
template <class V>
void sort(V arr[], int size)
{
    cout << "code to implement Generic Quick Sort"<<endl;
    cout << sizeof(V) << endl;
}
// Template Specialization: A function
// T-sp'd for char data type ->
template <>
void sort<char>(char arr[], int size)
{
    cout << "code to implement counting sort" << endl;
    cout << sizeof(char) << endl;
}

/*Class T-sp*/
template <class T>
class Test
{
  // Data members of test
public:
   Test()
   {
       // Initialization of data members
       cout << "General template object \n";
   }
   // Other methods of Test
};
//class T-sp'd for int
template <>
class Test <int>
{
public:
   Test()
   {
       // Initialization of data members
       cout << "Specialized for int - template object\n";
   }
};

int main()
{
    cout << endl << "<- Function T-sp ->" << endl;
    fun<char>('a');
    fun<int>(10);
    fun<float>(10.14);

    char arrc[3] = {'a','s','d'};
    int arri[3] = {2,1,3};
    sort(arri, 3);
    sort<char>(arrc, 3);

    cout << endl << "<- Class T-sp ->" << endl;
    Test<int> a;
    Test<char> b;
    Test<float> c;
    return 0;
}