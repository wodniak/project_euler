#include <iostream>
#include <map>

int calculateLetters(int number)
{
    //hardcoded letters count
    static std::map<int,int> letters = {
        {0, 0},
        {1, 3}, //one
        {2, 3}, //two
        {3, 5}, //three
        {4, 4}, //four
        {5, 4}, //five
        {6, 3}, //six
        {7, 5}, //seven
        {8, 5}, //eight
        {9, 4}, //nine
        {10, 3},    //ten
        {11, 6},    //eleven
        {12, 6},    //twelwe
        {13, 8},    //thirteen
        {14, 8},    //fourteen
        {15, 7},    //fifteen
        {16, 7},    //sixteen
        {17, 9},    //seventeen
        {18, 8},    //eighteen
        {19, 8},    //nineteen
        {20, 6},    //twenty
        {30, 6},    //thirty
        {40, 5},    //forty
        {50, 5},    //fifty
        {60, 5},    //sixty
        {70, 7},    //seventy
        {80, 6},    //eighty
        {90, 6},    //ninety
        {100, 7}};  //hundred

    int hundreds = number % 1000 / 100;
    int dozens  = number % 100 / 10;
    int units   = number % 10;
    int sum = 0;
    
    if (dozens == 0)
    {
        sum += letters[units];
    }
    else if (dozens == 1)
    {
        sum += letters[dozens*10+units];
    }
    else
    {
        sum += letters[dozens*10];
        sum += letters[units];
    }
    
    if(hundreds != 0)
        sum += letters[hundreds] + letters[100] + 3;

    return sum;
}

int main()
{
    int sumOfAll = 0;

    for (int i=1; i<1000; ++i)
    {
        sumOfAll += calculateLetters(i);
    }
    sumOfAll += 11;  //1000
    std::cout << sumOfAll << "\n";
}