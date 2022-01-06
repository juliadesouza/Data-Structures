#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Demo vector
    vector<int> arr = {1, 2, 10, 12, 15};

    // Push_back 0(1)
    arr.push_back(16);

    // Print all the elements
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }

    // // Size of the vector (No of elements)
    // cout << arr.size() << endl;

    // // Capacity of the vector
    // cout << arr.capacity() << endl;

    return 0;
}