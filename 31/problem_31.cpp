#include <iostream>

uint numberOfWays(const uint value)
{
    uint numberOfWays = 0;
    
    for(int a=value; a >=0; a-= 200) {
        for(int b=a; b >=0; b-= 100) {
            for(int c=b; c >=0; c-= 50) {
                for(int d=c; d >=0; d-= 20) {
                    for(int e=d; e >=0; e-= 10) {
                        for(int f=e; f >=0; f-= 5) {
                            for(int g=f; g >=0; g-= 2) {
                                    ++numberOfWays;
                            }
                        }
                    }
                }
            }
        }
    }
    return numberOfWays;
}


int main()
{
    int money = 200;  //pences
    std::cout << numberOfWays(money);

    return 0;
}