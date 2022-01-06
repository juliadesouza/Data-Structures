// Tokenizing a string denotes splitting a string with
// respect to some delimiter(s)

// Input
// "today is a sunny day"
// Output
// "today","is", "a", "sunny", "day"

#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
using namespace std;

int main()
{

    string input;
    getline(cin, input);
    //"this is a sunny day"

    //create a string stream object
    stringstream ss(input);

    // >> and << operators
    string token;
    vector<string> tokens;
    while (getline(ss, token, ' '))
    {
        tokens.push_back(token);
    }

    //print all all tokens
    for (auto token : tokens)
    {
        cout << token << ",";
    }

    return 0;
}
