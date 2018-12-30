#include <iostream>
#include<bits/stdc++.h>
#include <cmath>

/**
 *  Calculate how many divisors exist for given number
 */
unsigned int tau(unsigned int n)
{
    unsigned int result = 1;
    int c = 0;
    while (n % 2 == 0) 
    { 
        c++; 
        n /= 2; 
    } 
    result *= c+1;

    //iterate only for odd integers
    //there is only 1 prime number bigger then sqrt(n)
    for (int i = 3; i <= sqrt(n); i += 2) 
    { 
        c = 0;
        while (n % i == 0) 
        { 
            c++; 
            n /= i; 
        }
        result *= c+1;
    } 

    // when n is a prime number greater than 2 
    if (n > 2)
    {
        c = 1; 
        result *= c+1;
    } 
  
    return result;
}

unsigned int triangular_number(int d)
{
    unsigned int t_number = 1;      //first triangular number
    int x = 2;               

    while(tau(t_number) <= d)
    {
        //get next triangular number
        t_number += x;
        ++x;
    }

    return t_number;
}

int main()
{
    int d = 500;
    std::cout << triangular_number(d) << "\n";
    return 0;
}