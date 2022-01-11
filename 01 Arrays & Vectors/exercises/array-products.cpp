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