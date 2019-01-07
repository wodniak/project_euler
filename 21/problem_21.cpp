#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//count sum of divisors
int d(int n)
{
    int sum=0;
    for(int i=1; i<n; ++i)
    {
        if(n%i==0) {
            sum+= i;
        }
    }
    return sum;
}

unsigned int amicable_sum(const int low, const int high)
{
    unsigned int a = low, b, sum = 0;
    while(a <= high) {
        b = d(a);
        if(b > a && d(b) == a) 
            sum = sum + a + b;
        
        a++;
    }
    
    return sum;
}
int main()
{
    std::cout << amicable_sum(1, 10000) <<endl;
    return 0;
}