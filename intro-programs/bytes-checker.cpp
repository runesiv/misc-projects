// Check how any bytes are needed for a number

using namespace std;
#include <iostream>

int main (int argc, char* argv[])
{
    int i;
    int terms[32]; // Store of a0, a1 up to 32 bits in binary terms
    int number = atoi(argv[1]);

// Initialize the terms
    for (i=0; i < 32; i++){ terms[i] = 0;}
    for (i=0; i < 32; i++){
        terms[i] = number%2;
        number /= 2;
    }

// Write out result for a given number
    cout << "Number of bytes used= " << sizeof(number) << endl;
    for (i=0; i <32; i++){
        cout << "Term nr. " << i << "Value= " << terms[i];
        cout << endl;
    }
    return 0;
}
