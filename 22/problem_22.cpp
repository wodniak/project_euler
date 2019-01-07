#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <sstream>

using namespace std;

//read names from .txt and put them to set to have them sorted on the spot
set<string> readData(const char * fileName)
{
    set<string> data;
    ifstream file;
    string lineOfData;

    file.open(fileName);
    if(!file)
        exit(1);

    while(getline(file, lineOfData, ','))
    {
        stringstream lineStream(lineOfData);
        string name;
        while (lineStream >> name)
        {
            data.insert(name.substr(1,name.length()-2));    //in file all names are written in format "name", need to strip ""
        }
    }

    file.close();
    return data;
} 


//sum of alfabetic order of letters 
unsigned int countSingleScore(const string & name)
{
    int sum = 0;
    for(auto ch : name)
    {
        sum += ((int)ch - 64);  //in ASCII big letters starts at (dec) 65
    }

    return sum;
}


unsigned int countScores(const set<string>& allNames)
{
    unsigned int sum = 0;
    int pos = 1;
    for(auto it=allNames.begin(); it!=allNames.end(); ++it)
    {
        sum += pos * countSingleScore(*it);
        pos++;
    }

    return sum;
}

int main()
{
    set<string> allNames = readData("/home/gwozniak/Public/project_euler/22/p022_names.txt");
    cout << "Total of all the name scores: " << countScores(allNames) << endl;
    
    return 0;
}