// Steps:
// 01 - Divide the array in two parts
// 02 - Recursively sort both parts (left and right)
// 03 - Merge them into a single sorted array
// O(nlogn)

#include <iostream>
#include <vector>
using namespace std;

//helper method
void merge(vector<int> &array, int s, int e)
{
    int i = s;
    int m = (s + e) / 2;
    int j = m + 1;

    vector<int> temp;

    while (i <= m && j <= e)
    {
        if (array[i] < array[j])
        {
            temp.push_back(array[i]);
            i++;
        }
        else
        {
            temp.push_back(array[j]);
            j++;
        }
    }

    // Finished all the elements of one array so,
    // we need copy back the remaining elements

    // copy elements from the first array
    while (i <= m)
    {
        temp.push_back(array[i++]);
    }

    // or copy elements from the second array
    while (j <= e)
    {
        temp.push_back(array[j++]);
    }

    // copy back the elements to original array
    int k = 0;
    for (int idx = s; idx <= e; idx++)
    {
        array[idx] = temp[k++];
    }

    return;
}

//sorting method
void mergesort(vector<int> &arr, int s, int e)
{
    // base case
    if (s >= e)
    { // we have just one element in the array
        return;
    }

    // rec case
    int mid = (s + e) / 2;
    mergesort(arr, s, mid);
    mergesort(arr, mid + 1, e);
    return merge(arr, s, e);
}

int main()
{
    vector<int> arr{10, 5, 2, 0, 7, 6, 4};

    int s = 0;
    int e = arr.size() - 1;
    mergesort(arr, s, e);
    for (int x : arr)
    {
        cout << x << ",";
    }
    cout << endl;
    return 0;
}
