// Write a function that takes input an arrays of distinct
// integers, and returns the length of highest mountain.
// - A mountain id defined as adjacent integers that are
// strictly increasing until they reach a peak, at which the
// become strictly decrasing.
// - At least 3 numbers are required to form a mountain.

// Input
// [5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4]
// Output
// 9
#include <iostream>
#include <vector>
using namespace std;

int highest_mountain(vector<int> a)
{
    int n = a.size();

    int largest = 0;

    for (int i = 1; i <= n - 2;)
    {

        //check a[i] is peak or not
        if (a[i] > a[i - 1] and a[i] > a[i + 1])
        {
            //do some work
            int cnt = 1;
            int j = i;
            //cnt backwards (left)
            while (j >= 1 and a[j] > a[j - 1])
            {
                j--;
                cnt++;
            }
            //cnt forwards (right)
            while (i <= n - 2 and a[i] > a[i + 1])
            {
                i++;
                cnt++;
            }
            largest = max(largest, cnt);
        }
        else
        {
            i++;
        }
    }
    return largest;
}

int main()
{
    vector<int> arr{5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4};

    cout << highest_mountain(arr) << endl;

    return 0;
}