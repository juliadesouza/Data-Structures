// Given an array and an integer k, find the maximunfor
// each and every contiguous subarray of size k.
//  Input
//  N=9
//  arr[]={1 2 3 1 4 5 2 3 6}
//  k=3
//  Output
//  3 3 4 5 5 5 6

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void maxSubArrayK(vector<int> a, int k)
{

    //Algorithm
    int n = a.size();

    deque<int> Q(k);
    //1. Process only the first K elements
    int i;

    for (i = 0; i < k; i++)
    {
        //Logic here ...

        while (!Q.empty() && a[i] > a[Q.back()])
        {
            Q.pop_back();
        }

        Q.push_back(i);
    }

    //2. Remaining the elements of the array
    for (; i < n; i++)
    {
        cout << a[Q.front()] << " ";
        //Remove element from the left (contraction when an index lies outside the current window)
        while (!Q.empty() && Q.front() <= i - k)
        {
            Q.pop_front();
        }
        while (!Q.empty() && a[i] >= a[Q.back()])
        {
            Q.pop_back();
        }

        //always
        Q.push_back(i);
    }

    cout << a[Q.front()];
}

int main()
{

    vector<int> arr{1, 2, 3, 1, 4, 5, 2, 3, 5};
    int k = 3;
    maxSubArrayK(arr, k);
    return 0;
}