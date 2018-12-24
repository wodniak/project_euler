#include <iostream>
#include<bits/stdc++.h>

using namespace std; 
  
long long maxPrimeFactors(long long n) 
{ 
    long long maxPrime = -1; 
  
    while (n % 2 == 0) 
    { 
        maxPrime = 2; 
        n /= 2; 
    } 
   
    //iterate only for odd integers
    //there is only 1 prime number bigger then sqrt(n)
    for (int i = 3; i <= sqrt(n); i += 2) 
    { 
        while (n % i == 0) 
        { 
            maxPrime = i; 
            n /= i; 
        } 
    } 
   
    // when n is a prime number greater than 2 
    if (n > 2) 
        maxPrime = n; 
  
    return maxPrime; 
} 
int main()
{
    cout << maxPrimeFactors(600851475143L);
    return 0;
}