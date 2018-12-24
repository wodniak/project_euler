#include <iostream>
#include <time.h>
#include<bits/stdc++.h>
#include <cmath>

using namespace std;

//calculate greatest common divisor
unsigned long gcd(unsigned long x, int y)
{
    if (x % y == 0)
        return y;
    else
        gcd(y, x % y);
}

//calculate least common multiple
// with formula lcm(x,y) = (x*y) / gcd(x,y)
unsigned long lcm(int n)
{
    unsigned long number = 1;
    for (int x = 1; x <= n; ++x)
    {
        number = (number * x) / gcd(number, x);
    } 

    return number;
}

//using fundamental theorem of arithmetic
unsigned long lcm2(int n)
{
    double p[] = {1,2,3,5,7,11,13,17,19,23,29,
                 31,37,41,43,47,53,59,61,67,71,
                 73,79,83,89,97,101,103,107,109,113,127,131};   //list with some prime numbers
    int a[sizeof(p)/sizeof(double)] = {0};     //init with 0's
    unsigned long number = 1;                  //result
    int limit = sqrt(n);                       //a[i]=1 for each p[i]^2 > k
    bool check = true;

    int i = 1;
    while (p[i] <= n)
    {
        a[i] = 1;
        if (check)
        {
            if (p[i] < limit)
                a[i] = floor( log(n) / log(p[i]) );
            else
                check = false;
        }

        number *= pow(p[i], a[i]);
        ++i;
    }
    return number;
}

int main()
{
    int N = 20;

    clock_t begin_time = clock();
    cout << lcm(N) << endl;
    cout << float( clock () - begin_time ) / CLOCKS_PER_SEC << endl;
    
    begin_time = clock();
    cout << lcm2(N) << endl;
    cout << float( clock () - begin_time ) / CLOCKS_PER_SEC << endl;
    
    return 0;
}