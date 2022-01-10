// You are given a running stream of characters, output the
// first non repeating character in the string formed so far
// after every new character you get in input. Output -1 if
// such a character doesn't exist.std
// Input
// a a b c c b c d
// Output
// a -1 b b b -1 -1 d

#include <iostream>
#include <map>
#include <queue>
using namespace std;

vector<char> FindFirstNonRepeatingCharacter(string S)
{
    map<char, int> m;
    vector<char> result;
    queue<int> q;

    int n = S.length();

    for (int i = 0; i < n; i++)
    {
        char c = S[i];

        if (m.find(c) != m.end())
        { // ja foi adicionado
            m[c]++;
        }
        else
        {
            m[c] = 1;
            q.push(c);
        }

        while (!q.empty())
        {
            if (m[q.front()] > 1)
            {
                q.pop();
            }
            else
            {
                result.push_back(q.front());
                break;
            }
        }

        if (q.empty())
        {
            result.push_back('0');
        }
    }
    return result;
}