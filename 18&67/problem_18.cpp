#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

typedef unsigned int uint;

uint maxSum(std::vector<std::vector<int>>& triangle)
{
    //for each row
    for(int row = triangle.size()-2; row >= 0; --row)
    {
        for(int col=0; col < triangle[row].size(); ++col)
        {
            triangle[row][col] += std::max(triangle[row+1][col], triangle[row+1][col+1]);
        }
    }
    return triangle[0][0];
}


std::vector<std::vector<int>> createData(const char * fileName)
{
    std::ifstream inFile;
    std::vector<std::vector<int>> data;
    std::string rawInput;

    inFile.open(fileName);
    if (!inFile) {
        std::cout << "Unable to open file";
        exit(1);
    }
    //read each line
    while(std::getline(inFile, rawInput)) {
        std::vector<int>   lineData;
        std::stringstream  lineStream(rawInput);

        int value;
        // Read an integer at a time from the line
        while(lineStream >> value) {
            lineData.push_back(value);
        }

        data.push_back(lineData);
    }

    inFile.close();
    return data;
}


int main() 
{
    auto data = createData("/home/gwozniak/Public/project_euler/18/numbers.txt");
    auto data2 = createData("/home/gwozniak/Public/project_euler/18/p067_triangle.txt");

    std::cout << maxSum(data) << std::endl;
    std::cout << maxSum(data2) << std::endl;
    return 0;
}
