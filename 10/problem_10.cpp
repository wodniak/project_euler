#include <iostream>
#include<bits/stdc++.h>
#include <cmath>

//taken from problem_7
bool isPrime2(long long &number)
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

//lame solution
unsigned long long summation_of_primes(unsigned int N)
{
    long long number = 1;
    unsigned long long sum_of_primes = 2;
    //look for prime numbers
    while(number < N)
    {
        if(isPrime2(number))
            sum_of_primes += number;
        
        number += 2;
    }
    
    return sum_of_primes;
}

//sieve of eratosthenes - first implementation
//can be improved by not considering even numbers in sieve table
unsigned long long summation_of_primes1(unsigned int limit)
{
    unsigned int crosslimit = floor(sqrt(limit));
    bool sieve[limit] = {false};

    //mark even numbers
    for(int i = 4; i < limit; i += 2)
    {
        sieve[i] = true;
    }

    //go on every uneven number
    for(int n = 3; n < crosslimit; n+=2)
    {
        if (!sieve[n])  //n not marked so it is prime
        {
            for(unsigned int m=n*n; m < limit; m += 2*n)
            {
                sieve[m]=true;
            }
        }
    }

    //sum all prime numbers
    unsigned long int sum_of_primes = 0;
    for(int n=2; n<limit; ++n)
    {
        if(!sieve[n])
            sum_of_primes += n;
    }

    return sum_of_primes;
}


int main()
{
    unsigned int N = 5000000;
    std::cout << summation_of_primes(N) << "\n";
    std::cout << summation_of_primes1(N) << "\n";
    return 0;
}