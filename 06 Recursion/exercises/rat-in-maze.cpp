// Rat in a Maze
// You are given a an integer N and a grid of size NxN. The cells of the grid are numbered row
// wise from 1 to N^2. Rat wants to travel from cell number 1 to cell number N^2, and it can
// move in only right direction or down direction from a particular cell. There is exactly one path
// from source to destination as some cells are blocked. Help the rat to find the path.
// Input Format:
// In the function an integer N is given, and a 2D vector consisting of only 'O's And 'X's is given
// where 'X' represents blocked cell.
// Output Format:
// Return a vector of cell numbers of cells in path (in sequence).
// Output Format:
// Return a vector of cell numbers of cells in path (in sequence).
// Sample Testcase:
// Input:
// 4
// ООХО
// ОХОО
// ОООХ
// XXOO
// Output:
// 1 5 9 10 11 15 16


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool calc(int n, vector<vector<char>> c, vector<int> &v, int i = 0, int j = 0)
{
    if(i==n && j==n) return true;
    if(i==n+1 || j==n+1) return false;

    if(j != n && c[i][j+1] != 'X')
    {
        if(calc(n, c, v, i, j+1))
        {
            v.push_back( (i)*(n+1) + j+2 );
            return true;
        }
    }

    if(i != n && c[i+1][j] != 'X')
    {
        if(calc(n, c, v, i+1, j))
        {
            v.push_back( (i+1)*(n+1) + j+1 );
            return true;
        }
    }

    return false;
}

vector<int> findPath(int n, vector<vector<char>> c)
{
    vector<int> v;
    calc(n-1,c,v);
    v.push_back(1);
    reverse(v.begin(), v.end());
    return v;
}