// Testing how pointers work, now with matrices

using namespace std;
#include <stdio.h>
#include <iostream>

int main()
{
    int matr[2];
    int *pointer;
    
    pointer = &matr[0];
    matr[0] = 321;
    matr[1] = 322;

    printf("Adress of the matrix element matr[0]: %p\n", &matr[0]);
    printf("Adress of the matrix element matr[1]: %p\n", &matr[1]);
    printf("Value of the matrix element matr[0]: %d\n", matr[0]);
    printf("Value of the matrix element matr[1]: %d\n", matr[1]);
    printf("Value of the pointer: %p\n", pointer);
    printf("Value which the pointer points to: %d\n", *pointer);
    printf("Value which (pointer +1)points to: %d\n", *(pointer+1));
    printf("Adress of the pointer variable : %p\n", &pointer); 
} // End: function main()
