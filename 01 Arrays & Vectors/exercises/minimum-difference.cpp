// Minimum Difference
// Implement a function that takes in two non-empty arrays of integers, finds the pair of
// numbers (one from each array) who absolute difference is closest to zero, and returns a pair
// containing these two numbers, with the first number from array. Only one such pair will exist
// for the test.
// Input
//      Array1 = [23, 5, 10, 17, 30]
//      Array2 = [26, 134, 135, 14, 19]
// Output
//      17,19

#include <vector>
#include <algorithm>
#include <climits>
#include <cstdlib>
using namespace std;

pair<int, int> minDifference(vector<int> a1, vector<int> a2)
{

    pair<int, int> result;
    int minDiff = INT_MAX;

    sort(a2.begin(), a2.end());
    for (int num : a1)
    {
        auto idx = lower_bound(a2.begin(), a2.end(), num) - a2.begin();

        if (idx >= 1 && abs(num - a2[idx - 1]) < minDiff)
        {
            minDiff = abs(num - a2[idx - 1]);
            result.first = a2[idx - 1];
            result.second = num;
        }

        if (idx != a2.size() and a2[idx] - num < minDiff)
        {
            minDiff = a2[idx] - num;
            result.first = num;
            result.second = a2[idx];
        }
    }

    return result;
}