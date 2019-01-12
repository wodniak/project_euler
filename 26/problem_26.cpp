#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

/**
 *  Calculate recurring cycle from 1/val and return number of digits in reccuring cycle
 */ 
uint calcRecCycle(const uint val)
{
    std::vector<int> remainders;
    int rem = 10;
    
    while(true) {
        //g
        int x = val;
        do {
            x += val;
        } while(x <= rem);
        x -= val;
        //calc remainder
        rem = (rem % x) * 10;

        //check if remainder is already in vector
        if (std::find(remainders.begin(), remainders.end(),rem) != remainders.end()) {
            //check remainder position in vector
            for(int i = 0; i < remainders.size(); ++i)
            {
                if(remainders[i] == rem)
                    return remainders.size() - i;
            }
        } else {
            remainders.push_back(rem);
        }
    }
}

/**
 *  Get longest reccuring cycle from 1/n, where n <2,maxVal> 
 */
uint LongestReccuringCycle(const uint maxVal)
{
    uint longestFraction = 0;
    for(int val=maxVal; val >= 2; --val)
    {
        int m = calcRecCycle(val);
        std::cout << "number: " << val <<"\t" << m << std::endl;
        if(m > longestFraction) {
            longestFraction = m;
        }
    }
    return longestFraction;
}

int main()
{
    const uint maxDenominator = 1000;
    std::cout << LongestReccuringCycle(maxDenominator) << std::endl;
    return 0;
}