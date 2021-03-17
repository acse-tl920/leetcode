# include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int numChild = ratings.size();
        if(numChild < 2)
            return numChild;
        vector<int> allocation (numChild, 1);
        for(int i = 1; i < numChild ; i++)
        {
            if(ratings[i]>ratings[i-1])
            {
                allocation[i] = allocation[i-1]+1;
            }
        }
        for(int i = numChild -1 ; i>0;i--)
        {
            if(ratings[i]<ratings[i-1])
            {
                allocation[i-1] = max(allocation[i-1], allocation[i]+1);
            }
        }
        return accumulate(allocation.begin(), allocation.end(), 0);
    }
};