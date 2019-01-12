#include <iostream>

#define SIZE 1001
#define START SIZE/2

/**
 *  Brute force - get whole spiral
 *  sum diagonal in 2 different loops later
 *  1,111 ms
 */ 
unsigned long long sumOnDiagonals()
{
    unsigned long long spiral[SIZE][SIZE] = {0};    //create tabs with 0's
    uint num = SIZE * SIZE;
    uint length = SIZE-1;
    int row = 0;
    int col = 0;
    while (num != 1)
    {
        for(int c = length; c >= 0; --c)   //right to left
        {
            if (spiral[row][c] == 0)
            spiral[row][c] = num--;
        }

        for(int r = row+1; r <= length; ++r)  //up do down
        {
            if (spiral[r][col] == 0)
            spiral[r][col] = num--;
        }

        for(int c = col+1; c <= length; ++c)     //left to right
        {
            if (spiral[length][c] == 0)
            spiral[length][c] = num--;
        }

        for(int r = length-1; r > 0; --r)       //down to up
        {
            if (spiral[r][length] == 0)
            spiral[r][length] = num--;
        }

        ++col;
        ++row;
        length -= 1;
    }

    //printing routine
    for(int r = 0; r < SIZE; ++r)
    {
        for(int c = 0; c < SIZE; ++c)
        {
            std::cout << spiral[r][c] << "  ";
        }
        std::cout << std::endl;
    }

    //summing routine
    uint sum = 1;
    int rowSum = 0;
    int colSum = 0;
    for(int r = 0; r < SIZE; ++r)
    {
        sum += spiral[rowSum++][colSum++];
    }
    std::cout << sum << std::endl;
    int rowSum2 = 0;
    int colSum2 = SIZE-1;
    for(int r = 0; r < SIZE; ++r)
    {
        sum += spiral[rowSum2++][colSum2--];
    }
  
    return sum;
}

/**
 *  calculating only corners
 *  each corner is +2 then previous one, starting from 1
 *  0,004 ms
 */ 
uint sumOnDiagonals2()
{
    uint sum = 1;
    uint current_number = 1;
    for(int i = 2; i < SIZE; i+=2)
    {
        for (int corner = 0; corner < 4; ++corner)
        {
            current_number += i;
            sum += current_number;
        }
    }
    return sum;
}

int main()
{
    std::cout << sumOnDiagonals() << std::endl;
    std::cout << sumOnDiagonals2() << std::endl;
    return 0;
}