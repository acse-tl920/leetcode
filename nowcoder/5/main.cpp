#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N,K;
    cin>>N>>K;
    int sum=0;
    vector<vector<int> > arms;
    int i,j;
    for(i=0;i<N;i++)
    {
        vector<int> r(3,0);
        for(j=0;j<5;j++)
        {
            cin>>r[j];
        }
        arms.push_back(r);
    }
    int Max=0;
    if(K>=5)
    {
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                Max=max(Max,arms[j][i]);
            }
            sum+=Max;
        }
    }
    else
    {

    }
}
