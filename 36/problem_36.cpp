#include <iostream>
#include <bitset>
#include <string>

bool isPalindromic(std::string & val)
{
    int length = val.length();
    for(int i=0; i < length / 2; ++i)
    {
        if (val[i] != val[length-i-1])
            return false;
    }
    return true;
}

bool palindromicBase2(int number)
{
    std::string binary = std::bitset<32>(number).to_string(); //to binary

    //delete leading 0's
    std::string valShort;
    for(int i = 0; i<binary.length(); ++i)
    {
        if(binary[i] == '1')     //first 1
        {
            valShort = binary.erase(0,i);
            break;
        }
        else
            continue;
    }

    return isPalindromic(valShort);
}

bool palindromicBase10(int number)
{
    std::string decimal = std::to_string(number);
    return isPalindromic(decimal);
}

uint doubleBasePalindromes(int max)
{
    uint sum = 0;
    for(int number=1; number <= max; ++number)
    {
        if(palindromicBase10(number) && palindromicBase2(number)) {
            sum += number;
            std::cout << "number: " << number << std::endl;
        }
    }
    return sum;
}



int main()
{
    int max = 1000000;
    std::cout << doubleBasePalindromes(max) << " <- sum" << std::endl;
    return 0;
}