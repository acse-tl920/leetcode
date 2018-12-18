#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int s;
    cin>>n>>s;//硬币个数n和需要支付的车费s
    vector<int> coins;
    int i;
    int temp;
    int sum=0;
    int num=0;
    for(i=0;i<n;i++)
    {
        cin>>temp;
        coins.push_back(temp);
    }
    sort(coins.begin(),coins.end());
    for(i=0;i<n;i++)
    {
        sum+=coins[i];
        num++;
        if(sum>=s)
            break;
    }
    int t=num-1;
    for(i=t;i>-1;i--)
    {
        int a=sum-s;
            if(sum-coins[i]>=s){
                num--;
                sum-=coins[i];
            }
    }
    cout<<num;
}
