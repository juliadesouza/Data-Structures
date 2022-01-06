// You`re given a list of N strings. You'd like to
// concatenate trem together in some order such that the
// resulting string would be lexicographically smallest.
// Given the list of string, output the lexicographically
// smallest concatenation.

// Input
//      3
//      cb
//      cba
// Output
//      cbacbc

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

bool compare(string x, string y)
{
    return x + y < y + x;
}

int main()
{
    string arr[] = {"a", "ab", "aba"};
    int n = 3;

    sort(arr, arr + n, compare);

    for (auto s : arr)
    {
        cout << s;
    }

    return 0;
}