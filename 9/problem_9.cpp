#include <iostream>
#include<bits/stdc++.h>

//pure brute force
long pythagorean_triplet1(long long & n)
{
    int a,b,c;
    for(a=0; a < n; ++a)
    {
        b=a+1;
        for(b; b < n; ++b)
        {
            c = b+1;
            for(c; c < n; ++c)
            {
                if (a*a + b*b == c*c && a+b+c == n)
                    {
                        return a*b*c;
                    }
            }
        }
    }
    return -1;
}

//smarter bounds and only 1 inner loop
// c = sum-a-b
long pythagorean_triplet2(long long & n)
{
    int a,b,c;
    for(a = 3; a < (n-3)/3; ++a)
    {
        for(b = a + 1; b < (n-1-a)/2; ++b)
        {
            c = n - a - b;
            if ( c*c == a*a + b*b)
                return a*b*c;
        }
    }
    return -1;
}

//using parametrisation of pythagorean triplets
long long pythagorean_triplet3(long long & n)
{
    long long s2 = n /2;
    long long mlimit = floor(sqrt(s2)) - 1;
    long long sm, k, d, a, b, c;
    for(int m = 2; m < mlimit; ++m)
    {
        if(s2 % m == 0)
        {
            sm = s2 / m;
            while (sm % 2 == 0)
            {
                sm = sm / 2;
            }

            if(m % 2 == 1)
                k = m + 2;
            else   
                k = m + 1;

            while(k < 2*m && k <= sm)
            {
                if( sm % k == 0 && std::gcd(k,m) == 1)
                {
                    d = s2 / (k*m);
                    n = k - m;
                    a = d * (m*m - n*n);
                    b = 2*d*m*n;
                    c = d* (m*m + n*n);
                    return a*b*c;
                }
                
                k = k + 2;
            }
        }
    }

    return -1;
}

int main()
{
    long long n = 1000;
    std::cout << pythagorean_triplet1(n) << "\n";
    std::cout << pythagorean_triplet2(n) << "\n";
    std::cout << pythagorean_triplet3(n) << "\n";

    return 0;
}