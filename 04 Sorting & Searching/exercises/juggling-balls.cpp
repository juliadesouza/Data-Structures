// Juggling Balls
// Given an array containing balls of Red, Blue and Green Color in a random order. Your goal is
// to arrange these balls in sorted order - Red Balls, followed by Blue and then Green Balls. Red
// balls are denoted using number O, Blue using 1 and Green using 2.
// Note: Try to solve the problem in a single scan of the array without using extra space.
// Hint - read about DNF Algorithm .
// Input
//  {0, 0, 1, 2, 0, 1, 2, 0}
// Output
//  {0, 0, 0, 0, 1, 1, 2, 2}

#include <vector>
using namespace std;

vector<int> sortBalls(vector<int> a)
{
    //sort the balls in place in a single pass (O(N) time, O(1) space)
    int n = a.size();
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high)
    {
        switch (a[mid])
        {
        case 0:
            swap(a[low++], a[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(a[mid], a[high--]);
            break;
        }
    }

    return a;
}