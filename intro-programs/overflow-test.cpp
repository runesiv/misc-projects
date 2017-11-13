// Program to calculate 2**n to test overflow

using namespace std;
#include <iostream>
#include <cmath>

int main()
{
    int int1, int2, int3;

// Print to the terminal
    cout << "Read in exponential N for 2^N = \n";

// Read from the terminal
    cin >> int2;
    int1 = (int) pow(2., (double) int2);
    cout << "2^N * 2^N = " << int1 * int1 << "\n";
    int3 = int1 - 1;
    cout << "2^N*(2^N-1) = " << int1 * int3 << "\n";
    cout << "2^N -1 = " << int3 << "\n";
    return 0;
}
