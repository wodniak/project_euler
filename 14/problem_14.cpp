#include <iostream>

static unsigned int counter = 0;

int collatz_sequence(unsigned long long n)
{
    ++counter;

    if (n==1)
        return 0;

    if(n%2==0)
        collatz_sequence(n/2);
    else
        collatz_sequence(3*n + 1);
}

int main()
{
    int max_counter = 0;
    for(int i = 1; i < 1000000; ++i)
    {
        counter = 0;
        collatz_sequence(i);
        if(counter > max_counter)
        {
            max_counter = counter;
            std::cout << i << "\n";
        }
    }
    return 0;
}