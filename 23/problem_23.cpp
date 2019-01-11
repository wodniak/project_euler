#include <iostream>
#include <vector>
#include <set>
#define _MAX 28123
#define _MIN 24

using namespace std;

//count sum of divisors - brute force
//possible to use Sieve
int d(int n)
{
    int sum=0;
    for(int i=1; i<n; ++i)
    {
        if(n%i==0) {
            sum+= i;
        }
    }
    return sum;
}

//Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
uint sumOfNonAbundant()
{
    //compute all abundant numbers
    vector<int> allAbundants;
    for(int i = 1; i <= _MAX; ++i)
    {
        if(d(i) > i)
            allAbundants.push_back(i);
    }

    //make set with all abundant 2 numbers sum
    set<int> sum2Abundants;

    //compute all sums
    for(int i=0; i < allAbundants.size(); ++i)
    {
        for(int m=i; m < allAbundants.size(); ++m)
        {
            sum2Abundants.insert(allAbundants[i] + allAbundants[m]);
        }
    }

    uint sum = 0;
    for (int i = 1; i <= _MAX; ++i)
    {
        if (i < _MIN){
            sum += i;
        } else if(sum2Abundants.insert(i).second){
            cout << i << "   ";
            sum += i;
        }
    }

    return sum;
}

int main()
{
    cout << "sum : " << sumOfNonAbundant()  << endl;
    return 0;
}