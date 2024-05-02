#include <iostream>
#include <math.h>

using namespace std;

template <typename T>
class myVect {
    int sze;
    int max_sze;
    T* arr, * end;
    public :
    myVect() {
        arr = new T[128];
        sze = 0;
        max_sze = 128;
        end = arr;
    }
    myVect(int sz) {
        sze = sz;
        max_sze = pow(2, ceil(log(sze)/log(2)));
        arr = new T[max_sze];
        end = arr;
        for(int i=0; i<sze; i++) {
            end = NULL;
            end++;
        }
    }
    ~myVect() {
        delete [] arr;
    };
    
    int size() {
        return sze;
    }
    int max_size() {
        return max_sze;
    }
    T& operator[] (int x) {
        /*if( index < 0 || index >= size( ) )
            throw ArrayIndexOutOfBoundsException{ };*/
        if (x < 0 || x >= this->sze) {
            cerr << "Array index out of bound";
            exit(0);
        }
        return this->arr[x];
    }
    void pushv(T* y) {
        if(sze == max_sze) {
            end = new T[128];
            max_sze+=128;
            /*for(int i=0; i<127; i++) {
                end++;
            }*/
        }
        arr[sze++] = *y;
        end++;
    }
    void popv() {
        T* ptr = arr[sze-1];
        delete ptr;
        sze--;
    }
};

int main() {
    myVect<int> a(128);
    int sz = a.size();
    cout << a.max_size() << endl;
    for(int i=0; i<sz; i++) {
        cout << a[i] << endl;
    }
    a.pushv(new int(15));
    cout << a.max_size();
    for(int i=0; i<a.size(); i++) {
        cout << a[i] << endl;
    }
    cout << "last member=" << a[a.size()-1]<< endl;
    return 0;
}