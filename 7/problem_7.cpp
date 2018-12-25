#include <iostream>
#include<bits/stdc++.h>
#include <cmath>

using namespace std;

//awfully brute force method
bool isPrime(long long &number)
{
    bool result = true;
    //look for divisors
    for (int i = 2; i < number; ++i)
        if(number % i == 0)
            result = false;

    return result;
}

//works like a charm
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


long long find_nth_prime(int N)
{
    long long number = 1;

    //find Nth prime number
    for (int x = 1; x < N; number += 2)
    {
        //check if number is prime
        if (isPrime2(number))
            ++x;
    }
    return number - 2;
}

int main()
{
    int N = 10001;
    cout << find_nth_prime(N) << endl;
    return 0;
}