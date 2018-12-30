#include <iostream>

uint64_t factorial (uint64_t n)
{
    if (n<2) return n;
    return n*factorial(n-1);
}

uint64_t lattice_path(uint64_t n)
{
    uint64_t grid[n+1][n+1] = {0};

    //fill with 1's
    for(int i =0; i <= n; ++i)
    {
        grid[0][i] = 1;
        grid[i][0] = 1;
    }

    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=n; ++j)
        {
            grid[i][j] = grid[i-1][j] + grid[i][j-1];
        }
    }

    return grid[n][n]; 
}

uint64_t lattice_path2(uint64_t n)
{
    uint64_t paths = 1;
 
    for (int i = 0; i < n; i++) 
    {
        paths *= (2 * n) - i;
        paths /= i + 1;
    }
    //paths = factorial(n+n) / factorial(n) / factorial(n);
    return paths;
}

int main()
{
    uint64_t N = 20;
    std::cout << lattice_path(N) << "\n";
    std::cout << lattice_path2(N) << "\n";
    return 0;
}