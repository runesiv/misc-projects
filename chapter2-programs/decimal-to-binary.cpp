// Convert float from decimal to binary representation, using representation from subchapter 2.3
// Commando line argument get turned to (-1)^s X 2^n X r

using namespace std;
#include <iostream>
#include <cstdlib>
#include <cmath>

int main(int argc, char* argv[])
{
    float input_float = atof(argv[1]);
    int binary_rep[32];
    for (int m=0; m < 32; m++){
    binary_rep[m] = 0;
   } 
    
    /* Find the first bit for the sign */
    int binary_sign = input_float < 0 ? 1 : 0;
    if (binary_sign){
        input_float = -input_float;
    }
    binary_rep[0] = binary_sign;
    
    /* Find the  exponent for 2^n */
    int n = floor(log2(input_float));
    int n_remainder = n+127;
    for (int i=8; i > 0; i--){
        binary_rep[i] = n_remainder%2;
        n_remainder /=2;
    }
    
    /* Find the binary representation of the remainder as mantissa representation*/
    float r = input_float / pow(2.0, n);
    cout << input_float << " equals (-1)^" << binary_rep[0] << " X 2^(" << n << ") X " << r << endl; 
    r -=1.;
    for (int j=1; j < 23; j++){
        int k = 8+j;
        if  (r >= pow(2., -j)){  
            binary_rep[k] = 1;
            r -=  pow(2.,-j);}
        else {
            binary_rep[k] = 0;}
    }
   
   /*Print full result*/
   cout << "Or "<< input_float << " in binary is  (";
   for (int m=0; m < 32; m++){
   cout << binary_rep[m];
   } 
   cout << ")_2" << endl;
   return 0;
}
