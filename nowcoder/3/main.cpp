#include <iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int temp;
    int times=0;
    int i;
    vector<int> arr;
    for(i=0;i<n;i++)
    {
        cin>>temp;
        arr.push_back(temp);
    }
    for(i=0;i<n;i++)
    {
        if(arr[i]==i+1)
        {
            temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
            times++;
        }
    }
    cout<<times;
}
