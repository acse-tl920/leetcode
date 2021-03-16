# include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        int sum = 0;
        int greed = 0;
        int cookieSize = 0;
        while(greed < g.size() && cookieSize<s.size())
        {
            if(g[greed]<=s[cookieSize])
            {
                sum++;
                greed++;
                cookieSize++;
            }
            else
            {
                cookieSize++;
            }
        }
        return sum;
    }
};