/*Smart pointers*/
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
#include <memory>

using namespace std;

//manual smart pointer wrapper class
template <class T>
class SmtrPtrT {
    T * smtptr;
    public:
    explicit SmtrPtrT(T *a = nullptr)               //explicit, since the constr has only 1 arg, the conversion constr might plaay role
    {                                               //and it may not be able to resolve type like implicit conv of int to char or etc.
        smtptr = a;
        cout << "smtptr created" << endl;
    }
    /*T * getSmrtPtrI()
    {
        return smtptr;
    }*/
    //OR
    T operator * ()
    {
        return *smtptr;
    }
    ~SmtrPtrT()
    {
        cout << "smtptr destroyed" << endl;
        delete smtptr;
    }

};

//unique_ptr
class Foo
{
private:
    int x;
public:
    Foo(int a) : x(a){cout << "Foo constructed" << endl;};

    void printX(){
        cout << x << endl;
    };

    ~Foo(){cout << "Foo object destructor" << endl;};
};
//shared_ptr
class Doo
{
private:
    int x;
public:
    Doo(int a) : x(a){};
    int getv(){return x;}
    ~Doo(){cout << "~Doo" << endl;}
};
//weak_ptr
std::weak_ptr<int> gw;

void observe()
{
    std::cout << "gw.use_count() == " << gw.use_count() << "; ";
    // we have to make a copy of shared pointer before usage:
    if (std::shared_ptr<int> spt = gw.lock()) {
        std::cout << "*spt == " << *spt << '\n';
    }
    else {
        std::cout << "gw is expired\n";
    }
}

int main()
{
    {
        cout << "Manual scope started" << endl;
        /*Manual smart pointer definition. */
        int * d = new int(10);
        SmtrPtrT<int> sptr1 = SmtrPtrT<int>(d);
    }
    cout << "Manual scope ended" << endl;
    // distructor not getting called auto at the end. - > the code was crashing at f2->printX() after its move.
    //-------------------------------------------------------------------------------------------

    /*unique pointer
    - can use * or -> to access the value like normal pointers, becase the template of unique ptr
    - make_unique is exception safe. What is the exact difference in f2 and f3 is yet to see.
    - lightweight than shared and weak
      overloads the raw pointer class types
    - array of objects of unique ptr can be created
    - Where to use
    - How is it implemented?
    */
    cout << "--------- unique_ptr ---------" << endl;
    Foo * p = new Foo(5);
    unique_ptr<Foo> f1(p);                              //declaration like a class object
    unique_ptr<Foo> f1_1(p);                            //this is possible, hence ->
    unique_ptr<Foo> f2(new Foo(10));                    //but here we had to write Foo twice, more efforts, so use ->
    unique_ptr<Foo> f3 = make_unique<Foo>(20);          //make_unique is exception safe (eg. in foo(A* a, B* b); A is success and B is 
    unique_ptr<Foo> f4 = make_unique<Foo>(40);          //failure, then A will be freed with this, but not with the others)

    /* What is uniqueness?
    - only one pointer can take the ownership of the object
     */
    

    f1->printX();
    //OR
    (*f1).printX();

    f2->printX();

    f3->printX();
    
    Foo *f2_2 = f2.get();
    //equating unique pointer objects is not possible with =, but with move function
    unique_ptr<Foo> f2_1 = move(f2); //now f2 is a null pointer
    cout << "f2_1 : ";
    f2_1->printX();
    /*cout << "f2 : ";
    f2->printX();*/
    cout << endl;

    cout << "deleting f2_2 : ";
    f2_2->printX();
    cout << endl;
    delete f2_2;

    Foo *f3_1 = f3.get(); //just returns the address of f3

    Foo *f3_2 = f3.release(); //same as move ?? now f3 is a null pointer. Is f3_1 now a unique pointer?
    f3_1->printX();

    f4.reset(f3_1); //f4's original address value is deleted and value of f3_1 is assigned. Only works on object pointers, not unique pointers.

    //-------------------------------------------------------------------------------------------
    /*Shared ptr
    - allows multiple ownership of the managed object (keeps reference count)
    - once last shared ptr goes out of scope, managed ptr is deleted.
    - shared pointer control block (the one which increases the ref count - RC) is thread safe but
        the managed object is not.
            [Thread safe = ]
    - to avoid cyclic dependency (each of the 2 ptr objects is shared by the other), use one of them as weak pointer.
      [if you want to free one object, you'll need to free the shared_ptr, which will require freeing the other object, which will
      require freeing first object n so on...]
    - a pointer or a reference to a shared ptr is not considered a shared ptr but a noraml ptr, thus RC does not increase.
      So pass shared_ptr as a value
    */
    cout << endl << "--------- shared_ptr ---------" << endl;
    //shared_ptr<Doo> s1(new Doo(10));              //Two heap entries, 1 for the object Doo, other for the Control block
                                                    //(meta data such as ref-counts, type-erased deleter, etc)
    shared_ptr<Doo> s1 = make_shared<Doo>(10);      //Single heap entry for both of object and Control Block, hence use this
    shared_ptr<Doo> s2 = s1;    
    // if &s2=s1 or *s2=&s1 is used, the RC won't increment.
    cout << "Use counts of s1, s2 = " << s2.use_count() << ", " << s1.use_count() << endl;

    
    //-------------------------------------------------------------------------------------------
    /*weak ptr
    - Is a smart pointer that holds a non-owning ("weak") reference to an object that is managed by std::shared_ptr.
      i.e. has no ownership.
      *It must be converted to std::shared_ptr in order to access the referenced object.
    - Like std::shared_ptr, a typical implementation of weak_ptr stores two pointers:
        - a pointer to the control block; and
        - the stored pointer of the shared_ptr it was constructed from.
        - *A separate stored pointer is necessary to ensure that converting a shared_ptr to weak_ptr and then back works properly,
          It is not possible to access the stored pointer in a weak_ptr without locking it into a
          shared_ptr. 
    - 
   */
    cout << endl << "--------- weak_ptr ---------" << endl;
    {
        auto sp = std::make_shared<int>(42);
        gw = sp;

        observe();
    }

    observe(); //weak pointer should be destroyed, since the scope

    return 0;
}