// COMSC-210 | Final | Joaquin Felix
#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

const string DATA_FILE = "210-final-1-SP26.txt";

int main() 
{
    ifstream fin(DATA_FILE);

    if (!fin) 
    {
        cout << "ERROR: Could not openfile." << endl;
        return 1;
    }

    map<string, int> airport_counts;

    string origin;
    string destination;

    while (fin >> origin >> destination)
    {
        airport_counts[origin]++;
        airport_counts[destination]++;
    }

    fin.close();

    cout << "All airport traffic counts: " << endl;

    for (const auto& pair : airport_counts)
    {
        cout << pair.first
             << " "
             << pair.second 
             << endl;
    }

    return 0;
}