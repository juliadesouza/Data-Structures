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

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool outOfOrder(vector<int> arr, int i)
{
    int x = arr[i];
    if (i == 0)
    {
        return x > arr[1];
    }
    if (i == arr.size() - 1)
    {
        return x < arr[i - 1];
    }
    return x > arr[i + 1] or x < arr[i - 1];
}

pair<int, int> subarraySort(vector<int> arr)
{

    int smallest = INT_MAX;
    int largest = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
        int x = arr[i];

        if (outOfOrder(arr, i))
        {
            smallest = min(smallest, x);
            largest = max(largest, x);
        }
    }

    //next step find the right index where smallest and largest lie (subarray) for out solution
    if (smallest == INT_MAX)
    {
        return {-1, -1};
    }

    int left = 0;
    while (smallest >= arr[left])
    {
        left++;
    }
    int right = arr.size() - 1;
    while (largest <= arr[right])
    {
        right--;
    }

    return {left, right};
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};
    auto p = subarraySort(arr);
    cout << p.first << " and " << p.second << endl;

    return 0;
}