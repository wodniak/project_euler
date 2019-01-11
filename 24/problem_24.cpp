#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <sstream>
#include <algorithm>
uint silnia(uint n)
{
    if(n==0)
        return 1;
    else
        return n*silnia(n-1);
}

std::string permutationNr(std::vector<int> digits, uint num)
{
    std::string ans;
    int num_of_digits = 9; //number of digits
    while(ans.length() != 10)
    {
        int pos = 1;
        uint f_silnia = silnia(num_of_digits);
        for(int i=1; i < 10; ++i)
        {
            if(i*f_silnia < num){
                ++pos;
            } else {
                pos--;
                num -= pos * f_silnia;
                num_of_digits--;
                ans += std::to_string(digits[pos]);
                digits.erase(std::remove(digits.begin(), digits.end(), digits[pos]), digits.end());     //pretty spaghetti
                break;
            }
        }
    }
    return ans;
}


int main()
{
    std::vector<int> digits = {0,1,2,3,4,5,6,7,8,9};
    std::cout << permutationNr(digits, 1000000) << std::endl;
    
    return 0;
}