#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

  
// This function multiplies x with the number  
// represented by res[]. 
// res_size is size of res[] or number of digits in the  
// number represented by res[]. This function uses simple  
// school mathematics for multiplication. 
// This function may value of res_size and returns the  
// new value of res_size 
int multiply(int x, int res[], int res_size) 
{ 
    int carry = 0;  // Initialize carry 
  
    // One by one multiply n with individual digits of res[] 
    for (int i=0; i<res_size; i++) 
    { 
        int prod = res[i] * x + carry; 
  
        // Store last digit of 'prod' in res[]   
        res[i] = prod % 10;   
  
        // Put rest in carry 
        carry  = prod/10;     
    } 
  
    // Put carry in res and increase result size 
    while (carry) 
    { 
        res[res_size] = carry%10; 
        carry = carry/10; 
        res_size++; 
    } 
    return res_size; 
} 

void factorial(int n) 
{ 
    int res[1000]; 
  
    // Initialize result 
    res[0] = 1; 
    int res_size = 1; 
  
    for (int x=2; x<=n; x++) 
    {
        res_size = multiply(x, res, res_size); 
    }
  
    uint sum = 0;
    cout << "sum of digits "; 
    for (int i=0; i<res_size; i++) 
    {
        sum += res[i]; 
    }
    cout <<sum <<endl;;
} 

int main()
{
    int f = 100;
    factorial(f);
    return 0;
}