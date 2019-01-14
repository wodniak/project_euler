#include <iostream>
#include <cmath>
#include <string>
#include <set>

std::string power(const uint a, const uint b)
{
    uint length = 1 + b * log10(a);
    int number[length] = {0};
    number[length-1] = a;       //init with 2 at the end
    int temp, product;
    int num_of_digits = 0;

    //multiply b times 
    for(int i=2; i <= b; ++i)
    {
        temp = 0;
        //iterate over all digits, multiply them by b remembering about rest
        for(int m = 0; m<=num_of_digits; ++m)
        {
            product = a * number[length-1-m] + temp;
            number[length-1-m] = product % 10;
            temp = product / 10; 

            if (m == num_of_digits && temp > 0)
                num_of_digits++;
        }
    }

    std::string item = "";
    for(int i = 0; i < length; ++i)
    {
        item += std::to_string(number[i]);
    }
    return item;
}


uint distinctPowers(const uint a, const uint b)
{
    std::set<std::string> allItems;
    for(int i=2; i <= a; ++i)
    {
        for(int j=2; j <= b; ++j)
        {
            allItems.insert(power(i,j));
        }
    }
    return allItems.size();
}

int main()
{
    std::cout << distinctPowers(100,100) << std::endl;
    return 0;
}