// Array Products
// Implement a function that takes a vector of integers, and returns a vector of the same
// length, where each element in the output array is equal to the product of every other number
// in the input array. Solve this problem without using division.
// In other words, the value at output[i] is equal to the product of every number in the input
// array other than input[i]. You can assume that answer can be stored inside int datatype and
// no-overflow will occur due to products.
// Sample Input
// Both inputs and outputs are vectors.
// {1,2,3,4,5}
// Sample Output
// {120, 60, 40, 30, 24}

#include <iostream>
#include <vector>

using namespace std;

//Expected Complexity O(N)
vector<int> productArray(vector<int> arr)
{
    vector<int> output;
    int n = arr.size();
    int j = 0, k = 0;
    int multJ = 1, multK = 1;

    for (int i = 0; i < n; i++)
    {
        j = i - 1; // anda pra frente
        k = i + 1; // anda pra trás

        multJ = 1;
        multK = 1;

        while (j > -1)
        {
            multJ *= arr[j];
            j--;
        }

        while (k < n)
        {
            multK *= arr[k];
            k++;
        }

        output.push_back(multJ * multK);
    }

    return output;
}