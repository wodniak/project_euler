#include <iostream>
#include <math.h>

#define PHI 1.6180339887498948

uint nthFibDigitCount(const uint32_t numberOfDigits)
{
    return round( (log(10)*(numberOfDigits-1) + log(5)/2) / log(PHI) );
}


int main()
{
    std::cout << nthFibDigitCount(1000) << std::endl;
    return 0;
}