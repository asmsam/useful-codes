#include <iostream>
using namespace std;

void foo(int arr[][3]) {
    cout << arr[0][5] << endl;          //the indices consider 2nd row in continuation with the 1st row
}
//OR
void doo(int (*arr)[3]) {               //(*arr) is equivalent to arr[]
    cout << arr[0][5] << endl;          //the indices consider 2nd row in continuation with the 1st row
}


void printarray(char **array, int SIZE ){
    int i;
    int j;
    for( j = 0; j < SIZE; j++ ){
        for( i = 0; i < SIZE; i ++){
            printf( "%c ", array[j][i] );
        }
        printf( "\n" );
    }
}

int main()
{
    int a[][3] = {{1,2,3},{4,5,6}};     //writing 3 for the column size is mandatory in C++
    foo(a);
    
    /*-------------------*/
    /*How to dynamically declare a 2D array using malloc*/
    char **array;
    int SIZE;
    
    array = (char **) malloc(SIZE * sizeof(char*));
      // Note: cleaner alternative syntax
      // array = malloc(sizeof *array * SIZE);

    for (int row = 0; row<SIZE; row++) {
        // Shown here to help show difference between this malloc() and the above one.
        array[row] = (char *) malloc(SIZE * sizeof(char));
        // Note: cleaner alternative syntax
        // array[row] = malloc(sizeof(**array) * SIZE);
    }
    // Initialize each element.
    for (int row = 0; row<SIZE; row++) {
        for (int col = 0; col<SIZE; col++) {
            array[row][col] = 'a';  // or whatever value you want
        }
    }
    printarray(array, SIZE);

    return 0;
}