#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> commonElements(vector<int> v1, vector<int> v2)
{

    unordered_map<int, int> map;
    vector<int> output;

    // Adicionando o primeiro array
    for (int i = 0; i < v1.size(); i++)
    {
        int element = v1[i];
        map[element] = 1;
    }

    // Adicionando o segundo array
    for (int i = 0; i < v2.size(); i++)
    {
        int element = v2[i];
        if (map.find(element) != map.end())
        {
            map[element]++;
        }
        else
        {
            map[element] = 1;
        }
    }

    // Preenchendo o vetor de saída
    for (auto x : map)
    {
        if (x.second > 1)
        {
            output.push_back(x.first);
        }
    }

    sort(output.begin(), output.end());
    return output;
}

/*
vector<int> commonElements(vector<int> v1, vector<int> v2)
{
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    vector<int> v;
    unordered_map<int, bool> map;

    for(auto x : v1) 
        map[x] = true;

    for(auto x : v2)
    {
        if(map[x] == true)
            v.push_back(x);
    }

    return v;
}
*/