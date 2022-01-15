// Staircase Search
// You are given a M x N matrix which is row wise and column wise sorted. You have to search
// the index of a given integer K in the matrix.

// Input Format:
// Function contains integer M, integer N ,2D vector containing integers and an integer k.
// Output Format:
// Return a pair of integers {x,y} where x is the row index and y is column index of k in the
// matrix.

// Expected Complexity:
// Linear

#include <vector>
using namespace std;

pair<int, int> search(int m, int n, vector<vector<int>> v, int k)
{
    //write your code here.
    pair<int, int> output;
    // linhas
    int x = 0;
    while (x < m)
    {
        if (k >= v[x][0] && k <= v[x][m - 1])
        {
            break;
        }
        x++;
    }

    int y = 0;
    while (y < n)
    {
        if (v[x][y] == k)
        {
            break;
        }
        y++;
    }
    output.first = x;
    output.second = y;
    return output;
}

// #include<bits/stdc++.h>
// using namespace std;
// pair<int,int> search(int m, int n, vector<vector<int>> v, int k){
//     int i=m-1;
//     int j=0;
//     while(j<n && i>=0){
//         if(v[i][j]==k){
//             break;
//         }
//         else if(v[i][j]<k){
//             j++;
//         }
//         else{
//             i--;
//         }
//     }
//     pair<int,int> p={i,j};
//     return p;
// }