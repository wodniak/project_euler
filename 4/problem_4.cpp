#include <iostream>
#include <deque>

using namespace std;

static unsigned int max_palindrome = 0;

void collect_digits(deque<int>& digits, unsigned int num) {
    if (num > 9) {
        collect_digits(digits, num / 10);
    }
    digits.push_back(num % 10);
}

void check_palindrome(unsigned int x, unsigned int y)
{
    deque<int> digits;
    unsigned int number = x * y;
    collect_digits(digits, number);
    bool is_palidrome = true;

    while(digits.size() >= 2)
    {
        if (digits.front() == digits.back())
        {
            digits.pop_back();
            digits.pop_front();
        }
        else
        {
            is_palidrome = false;
            break;
        }
    }

    if (is_palidrome && number > max_palindrome)
    {
        max_palindrome = number;
        cout << max_palindrome << endl;
    }

}

int main()
{
    for (int x = 999; x >= 100; --x)
    {
        for (int y = x; y >= 100; --y)
        {
            check_palindrome(x,y);


            if (x*y < max_palindrome)
                break;
        }
    }
    cout << max_palindrome;
}