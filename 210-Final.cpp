// COMSC-210 | Final | Joaquin Felix
#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

const string DATA_FILE = "210-final-1-SP26.txt";

void print_range(
    const map<string, int>& airport_counts,
    int low,
    int high
);

int main() 
{
    ifstream fin(DATA_FILE);

    if (!fin) 
    {
        cout << "ERROR: Could not open file." << endl;
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

    cout << "All airport traffic counts: " 
         << endl;

    for (const auto& pair : airport_counts)
    {
        cout << pair.first
             << " "
             << pair.second 
             << endl;
    }

    int max_count = 0;

    for (const auto& pair : airport_counts)
    {
        if (pair.second > max_count)
        {
            max_count = pair.second;
        }
    }

    cout << endl;

    cout << "Busiest airport(s) with count "
         << max_count
         << ":" << endl;
         
    for (const auto& pair : airport_counts)
    {
        if (pair.second == max_count)
        {
            cout << pair.first
                 << " "
                 << pair.second
                 << endl;
        }
    }

    cout << endl;

    print_range(airport_counts, 1, 10);

    cout << endl; 

    print_range(airport_counts, 11, 100);

    return 0;
}

void print_range(
    const map<string, int>& airport_counts,
    int low,
    int high
)
{
    cout << "Airports with traffic in range ["
         << low
         << ", "
         << high
         << "]:" << endl;
    
    for (const auto& pair : airport_counts)
    {
        if (pair.second >= low &&
            pair.second <= high)
        {
            cout << pair.first
                 << " "
                 << pair.second
                 << endl;
        }
    }
}