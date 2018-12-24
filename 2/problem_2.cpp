#include <iostream>
int main()
{
    unsigned long sum = 0;
    unsigned long prev = 1;
    unsigned long curr = 2;
    do
    {
        if (curr % 2 == 0)
            sum += curr;

        curr = curr + prev;
        prev = curr - prev;
    }while (curr < 4000000);

    std::cout << sum << std::endl;
    return 0;
}