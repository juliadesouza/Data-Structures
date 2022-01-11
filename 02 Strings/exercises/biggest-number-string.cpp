// Biggest Number String
// You are given a vector of numbers. You want to concatenate these numbers together to form
// the lexicographically largest number. Print that largest number number. You can't rearrange
// the digits of any number, however you can place the numbers next to each other in any
// order.
// Input
// 10,11,20,30,3
// Output
// 330201110

#include <string>
#include <vector>
using namespace std;

bool compare(string x, string y)
{
    return x + y > y + x;
}

string concatenate(vector<int> numbers)
{

    int n = numbers.size();
    vector<string> arr;

    for (int i = 0; i < n; i++)
    {
        arr.push_back(to_string(numbers[i]));
    }

    sort(arr.begin(), arr.end(), compare);

    string str = "";

    for (int i = 0; i < n; i++)
    {
        str += arr[i];
    }

    return str;
}