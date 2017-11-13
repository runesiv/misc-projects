// A comment line begins like this in C++ programs

using namespace std;

#include <iostream>
#include <cstdlib>
#include <cmath>

int main (int argc, char*argv[])
{
// Convert the text argv[1] to double using atof:
    double r = atof(argv[1]);
    double s = sin(r);
    cout <<"Hello World! sin("<< r <<")=" << s << endl;
// Success
    return 0;
}
