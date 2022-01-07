// // Monotonic search - you can discard either the
// // left part or the right part

// There is a long wire along a straight line, which contains
// N bird nests at position x1, x2, ..., xN.
// There are B (B<=N) birds, which become angry towards
// each other onde put into a nest. To put the birds from
// hurting each other you want  to assign birds to nests such
// that minumin distance between any two birds is as large
// as possible. What is the largest minimun distance?

// Input
// N = 5 nests
// B = 3 birds
// Nests = [1,2,4,8,9]

// Output
// 3

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canPlaceBirds(int B, int N, vector<int> nests, int sep)
{

    int birds = 1;
    int location = nests[0];

    for (int i = 1; i <= N - 1; i++)
    {
        int current_location = nests[i];
        if (current_location - location >= sep)
        {
            birds++;
            location = current_location;

            if (birds == B)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int B = 3;
    vector<int> nests{1, 2, 4, 8, 9};
    //sorting
    sort(nests.begin(), nests.end());
    int N = nests.size();

    //Binary Search
    int s = 0;
    int e = nests[N - 1] - nests[0];
    int ans = -1;

    while (s <= e)
    {
        int mid = (s + e) / 2;

        bool canPlace = canPlaceBirds(B, N, nests, mid);
        if (canPlace)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}