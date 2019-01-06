#include <iostream>
#include <cmath>
#include <string>

int main()
{
    uint length = 1 + 1000 * log10(2);
    int number[length] = {0};
    number[length-1] = 2;       //init with 2 at the end
    int temp, product;
    int num_of_digits = 0;

    //multiply 1000 times 
    for(int i=2; i <= 1000; ++i)
    {
        temp = 0;
        //iterate over all digits, multiply them by 2 remembering about rest
        for(int m = 0; m<=num_of_digits; ++m)
        {
            product = 2 * number[length-1-m] + temp;
            number[length-1-m] = product % 10;
            temp = product / 10; 

            if (m == num_of_digits && temp > 0)
                num_of_digits++;
        }
    }

    uint sum = 0;
    for(int i=0; i<length; ++i)
    {
        sum += number[i];
    }

    std::cout << sum << "\n";
    return 0;
}