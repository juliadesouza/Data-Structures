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
#include <iostream>
#include <utility>
using namespace std;

pair<int, int> minDifference(vector<int> a, vector<int> b)
{
    //Complete this method
    int n = a.size();
    int m = b.size();
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int diff = a[i] - b[]
        }
    }
    
}

int main()
{
    vector<int> v = {-1, 2, 3, 4, -2, 6, -8, 3};
    cout << maxSubarraySum(v) << endl;

    return 0;
}