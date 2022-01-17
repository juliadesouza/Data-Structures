// Given an array of size at-least two, find the smallest
// subarray that needs to be sorted in place so that entire
// input array becomes sorted.
// If the input array is already sorted, the function should
// return [-1,-1], otherwise return the start & end index of
// smallest subarray.

// Input
// a1 = [1,2,3,4,5,8,6,7,9,10,11]
// Output
// [5,7]

#include <vector>
#include <algorithm>
using namespace std;

//This is O(NLogN) Solution, O(N) Solution also exists
pair<int, int> subarraySorting(vector<int> a)
{

    vector<int> b(a);
    sort(a.begin(), a.end());

    //do comparison
    int i = 0;
    int n = a.size();
    while (i < n and a[i] == b[i])
    {
        i++;
    }
    int j = a.size() - 1;
    while (j >= 0 and a[j] == b[j])
    {
        j--;
    }
    //already sorted
    if (i == a.size())
    {
        return {-1, -1};
    }
    return {i, j};
}