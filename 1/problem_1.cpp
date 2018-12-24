#include <iostream>
int main()
{
    unsigned long sum = 0;
    for (int i = 0; i < 1000; ++i)
    {
        if (i % 3 == 0 || i % 5 == 0)
            sum += i;
    }
    std::cout << "sum: " << sum;
    return 0;
}