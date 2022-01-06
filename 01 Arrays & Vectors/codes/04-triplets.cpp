// Given an array containing N integers, and an number S
// denoting a target sum.
// Find all distintic integers that can add up to forme a target
// sum. The number in each triplet should be ordered in
// ascendind order, and triples should be ordered too.
// Return empty array if no such triplet exists.

// Input
// array = [1,2,3,4,5,6,7,8,9,15]
// target = 18
// output
// [[1,2,15], [3,7,8], [4,6,8],[5,6,7]]

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> triplets(vector<int> arr, int targetSum)
{
    //Logic
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> result;

    // Pick every a[i], pair sum for remaining part
    for (int i = 0; i <= n - 3; i++)
    {

        int j = i + 1;
        int k = n - 1;

        //two pointer approach
        while (j < k)
        {
            int current_sum = arr[i];
            current_sum += arr[j];
            current_sum += arr[k];

            if (current_sum == targetSum)
            {
                result.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;
            }
            else if (current_sum > targetSum)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }
    return result;
}

int main()
{
    vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 15};
    int S = 18;

    auto result = triplets(arr, S);

    for (auto v : result)
    {
        for (auto no : v)
        {
            cout << no << ",";
        }
        cout << endl;
    }

    return 0;
}
