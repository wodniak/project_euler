#include <iostream>
using namespace std;

//brute force implementation
unsigned long sum_square_diff(int n)
{
    unsigned long sum = 0, sum1 = 0;
    
    for (int i = 1; i <= n; ++i)
    {
        sum += i * i;
        sum1 += i;
    }
    return sum1 * sum1 - sum;
}


//special formula implementation
unsigned long sum_square_diff2(int n)
{
    unsigned long sum1 = n * (n + 1) / 2;
    unsigned long sum = n * (2*n + 1)*(n + 1) / 6;
    return sum1 * sum1 - sum;
}


int main()
{
    int N = 100;
    cout << sum_square_diff(N) << "\n";
    cout << sum_square_diff2(N) << "\n";
    return 0;
}