#include <vector>
#include <climits>
using namespace std;

vector<int> maxInWindow(vector<int> input, int k)
{
    int n = input.size();
    int start, end, max;
    vector<int> output;

    for (int i = 0; i <= n - k; i++)
    {
        max = input[i];
        start = i;
        end = i + k;

        while (start < end)
        {
            if (input[start] > max)
            {
                max = input[start];
            }
            start++;
        }
        output.push_back(max);
    }
    return output;
}