// Testing how truncation and loss of prescision works in c++
// Illustrate further that algorithms matter: standard deviations by two different methods

using namespace std;
#include <iostream>
#include <cmath>

int main()
{
    int i;
    float sum, sumsq2, xbar, sigma1, sigma2;
    //Declare a array with fixed dimension
    float x[127];
    // Initialize the data set from lecture notes
    for (i=0; i < 127; i++) {
        x[i] = i + 100000.;
    }
    // The variable sum is sum over all elements
    // The variable sumsq is the sum over x^2
    sum = 0.;
    sumsq2 = 0.;
    
    // Textbook-algorithm
    for (i =0; i < 127; i++) {
        sum += x[i];
        sumsq2 += pow((double) x[i],2.);
    }
    // Calculate the standard deviation
    xbar = sum/127.;
    sigma1 = sqrt((sumsq2 - sum*xbar)/126.);
    
    // The second algorithm
    sumsq2 = 0.;
    for (i =0; i < 127; i++) {
        sumsq2 += pow((double) (x[i] - xbar),2.);
    }
    sigma2 = sqrt(sumsq2/126.);
    cout << "xbar = " << xbar << " sigma1 = " << sigma1 << " sigma2 = " << sigma2;
    cout << endl;
    return 0;
} // End: function main()
