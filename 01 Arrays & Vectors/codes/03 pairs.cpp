// Given an array containing N integers, and an number S
// denoting a target sum.
// Find two distintics integers that can pair up to form target
// sum. Let us assume there will be be only one such pair.

// Input
// array = [10, 5, 2, 3, -6, 9, 11]
// S = 4
// Output
// [10, -6]

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> pairSum(vector<int> arr, int Sum)
{
    //Logic
    unordered_set<int> s;
    vector<int> result;

    for (int i = 0; i < arr.size(); i++)
    {

        int x = Sum - arr[i];
        if (s.find(x) != s.end())
        {
            result.push_back(x);
            result.push_back(arr[i]);
            return result;
        }
        //insert the current no inside set
        s.insert(arr[i]);
    }
    return {};
}

int main()
{

    vector<int> arr{10, 5, 2, 3, -6, 9, 11};
    int S = 4;

    auto p = pairSum(arr, S);
    if (p.size() == 0)
    {
        cout << "No such pair";
    }
    else
    {
        cout << p[0] << "," << p[1] << endl;
    }

    return 0;
}