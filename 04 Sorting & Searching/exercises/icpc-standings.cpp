// ICPC Standings
// Usually, results of competitions are based on the scores of participants. However, we are
// planning a change for the next year of ICPC. During the registration each team will be able to
// enter a single positive integer : their preferred place in the ranklist. We would take all these
// preferences into account, and at the end of the competition we will simply announce a
// ranklist that would please all of you.
// But wait... How would that ranklist look like if it won't be possible to satisfy all the requests?
// Suppose that we already have a ranklist. For each team, compute the distance between their
// preferred place and their place in the ranklist. The sum of these distances will be called the
// badness of this ranklist.

// Goal
// Given team names and their preferred placements find one ranklist with the minimal possible
// badness.

// Input
// The input is stored in a vector<pair<string, int> > where the each pair stores the team
// name & its preferred rank.
//     WinOrBooze 1
//     BallOfDuty 2
//     WhoKnows 2
//     BholeChature 1
//     DCE Coders 5
//     StrangeCase 7
//     Whoknows 7
// Output
//     5

// Hints
// Can you do use a NLogN sorting algorithm ?
// Think how you can improve the complexity to O(N).

#include <vector>
#include <unordered_map>
using namespace std;

int badness(vector<pair<string, int>> teams)
{
    //Complete this function to return the min badness
    int n = teams.size();
    int badness = 0;
    int minD = INT_MAX;

    unordered_map<int, bool> map;
    for (int i = 1; i <= n; i++)
    {
        map[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        int preferred = teams[i].second;

        if (map[preferred] == false)
        {
            map[preferred] = true;
        }
        else
        {
            for (int j = 1; j <= map.size(); j++)
            {
                if (map[i] == false)
                {
                    int d = abs(preferred - j);
                    minD = min(minD, d);
                }
            }
            badness += minD;
        }
    }

    return badness;
}

/*#include<bits/stdc++.h>
using namespace std;
int badness(vector<pair<string,int> > teams){
    //Complete this function to return the min badness
    int n = teams.size();
    //create a count array init with 0
    vector<int> cnt(n+1,0);
    
    
    for(int i=0;i<n;i++){
        cnt[teams[i].second]++;
    }
    
    int pos = 1;
    int sum = 0;
    for(int i=1;i<=n;i++){
        while(cnt[i]){
            sum += abs(pos-i);
            cnt[i]--;
            pos++;
        }
    }
       
    return sum;
}*/