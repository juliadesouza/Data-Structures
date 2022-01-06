// Given an array containing N integers, find length of
// longest band.

// A band is defined as a subsequence which can be re-
// ordered in such a manner all elements appear consecutive
// (i.e. with absolute diferrence of 1 between
// neighbouring elements)

// A longest band is the band (subsequence) which contains
// maximum integers.

// Input
// [1,9,3,0,18,5,2,4,10,7,12,6]
// Output
// 8

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int largestBand(vector<int> arr)
{
    int n = arr.size();
    unordered_set<int> s;

    //Data inside a set
    for (int x : arr)
    {
        s.insert(x);
    }

    //Iterate over the arr
    int largestLen = 1;

    for (auto element : s)
    {
        int parent = element - 1;

        if (s.find(parent) == s.end())
        {
            //find entire band / chain starting from element
            int next_no = element + 1;
            int cnt = 1;

            while (s.find(next_no) != s.end())
            {
                next_no++;
                cnt++;
            }

            if (cnt > largestLen)
            {
                largestLen = cnt;
            }
        }
    }

    return largestLen;
}

int main()
{

    vector<int> arr{1, 9, 3, 0, 18, 5, 2, 10, 7, 12, 6};
    cout << largestBand(arr) << endl;

    return 0;
}