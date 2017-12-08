// Testing how pointers work

using namespace std;
#include <stdio.h>

int main()
{
    int var;
    int *pointer;
    
    pointer = &var;
    var = 421;
    
    printf("Adress of the integer variable var: %p\n", &var);
    printf("Value of the integer variable var: %d\n", var);
    printf("Value of the pointer variable: %p\n", pointer);
    printf("Value which the pointer is pointing at: %d\n", *pointer);
    printf("Adress of the pointer variable : %p\n", &pointer); 
} // End: function main()
