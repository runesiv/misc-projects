// Testing how truncation and loss of prescision works in c++
// The first is by straight calculation

using namespace std;
#include <iostream>
#include <cmath>

// type float: 32 bits
// type double: 62 bits

#define    TYPE    double
#define    PHASE(a)     (1 - 2 * (abs(a) % 2))
#define    TRUNCATION    1.0E-10

//function declation
TYPE    factorial(int);

int main()
{
    int n;
    TYPE x, term, sum;
    for(x =0.0; x < 100.0; x+=10.0) {
        sum = 0.0;
        n = 0;
        term = 1;
        while(fabs(term) > TRUNCATION) {
            term = PHASE(n) * (TYPE) pow((TYPE) x, (TYPE) n) / factorial(n);
            sum += term;
            n++;
        }    // end of while()-loop
        cout << " x = " << x << " exp = " << exp(-x) << " series = " << sum;
        cout << " number of terms = " << n << endl;
    }     //end of for()-loop
    return 0;
}    //End: function main()

// The function factorial()
// calculates and returns n!

TYPE factorial(int n)
{
    int loop;
    TYPE fac;
    for(loop=1, fac = 1.0; loop <= n; loop++) {
        fac *= loop;
    }
    return fac;
}    //End: function factorial()
