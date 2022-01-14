#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

char firstRepeatChar(string input)
{
    unordered_set<char> set;

    for (int i = 0; i < input.length(); i++)
    {
        char ch = input[i];
        if (set.find(ch) != set.end())
        { // repeated letter
            return ch;
        }
        set.insert(ch);
    }

    return '\0';
}
