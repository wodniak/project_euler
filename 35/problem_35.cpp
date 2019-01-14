#include <iostream>
#include <math.h>

bool isPrime(long long number)
{
    if (number == 1)
        return false;
    else if (number < 4)
        return true;
    else if (number % 2 == 0)
        return false;
    else if (number < 9)
        return true;
    else if (number % 3 == 0)
        return false;
    else
    {
        //prime = 6k +/- 1
        int r = floor(sqrt(number));
        int f = 5;
        while (f <= r)
        {
            if (number % f == 0)
                return false;
            if (number % (f+2) == 0)
                return false;
            
            f += 6;
        }
    }

    return true;
}

bool checkRotations(int num)
{
    int numOfDigits = 0;
    int divisor = 1;
    int m = num;
    while (m != 0)  //get number of digits
    {
        m /= 10;
        ++numOfDigits;
        divisor *= 10;
    }
    divisor /= 10;
 
    for(int n=0; n < numOfDigits-1; ++n)
    {
        // num = num - lastDigit * its position + lastDigit
        //num = (num - int((num / divisor)) * divisor) * divisor + int((num / divisor));      //get next rotated number

        int d = num % 10;
        num = d * divisor + num / 10;

        if(!isPrime(num)) {
            return false;
        }
    }
    return true;
}

uint circularPrimes(const uint maxVal)
{
    int count = 0;
    for(int i=1; i < maxVal; ++i)
    {
        if(isPrime(i)) {
            if(checkRotations(i)) {
                ++count;
                std::cout << i << std::endl;
            }
        }
    }

    return count;
}


int main()
{
    uint maxVal = 1000000; 
    std::cout <<circularPrimes(maxVal) << std::endl;
}