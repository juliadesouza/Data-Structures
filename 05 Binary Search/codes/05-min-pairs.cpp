// Given two non-empty arrays, find the pair of numbers
// (one from each array) whose absolute sifference is
// minimun. Print the any one pair with the smallest
// difference.

// Input
// a1 = [-1,5,10,20,3]
// a2 = [26,134,135,15,17]

// Output
// [20, 17]

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

void min_pair(vector<int> a1, vector<int> a2)
{

    //Sort the array
    sort(a2.begin(), a2.end());

    int p1, p2;
    int diff = INT_MAX;

    //iteratte over 1 array and look for closes elements in the second array
    for (int x : a1) //
    {
        auto lb = lower_bound(a2.begin(), a2.end(), x) - a2.begin(); // index value

        //left
        if (lb >= 1 && x - a2[lb - 1] < diff)
        { // update minimum difference
            diff = x - a2[lb - 1];
            p2 = x;
            p1 = a2[lb - 1];
        }
        //greater / right
        if (lb != a2.size() && a2[lb] - x < diff)
        {
            diff = a2[lb] - x;
            p1 = x;
            p2 = a2[lb];
        }
    }
    cout << "Min Pair " << p1 << " and " << p2 << endl;
    return;
}

int main()
{

    vector<int> a1 = {-1, 5, 10, 20, 3};
    vector<int> a2 = {26, 134, 135, 15, 17};
    min_pair(a1, a2);

    return 0;
}