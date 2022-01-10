// Maximum Subarray Sum
// Implement a function that takes an input a vector of integers, and prints the maximum
// subarray sum that can be formed. A subarray is defined as consecutive segment of the
// array. If all numbers are negative, then return 0.
// Input
// 1
// {-1,2,3,4,-2,6,-8,3}
// Output
// 13

#include <vector>
#include <iostream>
using namespace std;

int maxSubarraySum(vector<int> arr)
{
    //Complete this function, your function should return the maximum subarray sum
    int n = arr.size();
    int cs = 0; // current sum
    int ms = 0; // max sum

    int i = 0;
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        cs += arr[i];
        ms = max(ms, cs);
        if (cs < 0)
        {
            cs = 0;
        }
    }

    return ms;
}

int main()
{
    vector<int> v = {-1, 2, 3, 4, -2, 6, -8, 3};
    cout << maxSubarraySum(v) << endl;

    return 0;
}