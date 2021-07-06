#include "main.h"

using namespace std;

void merge_sort(vector<int> & nums, int l, int r, vector<int> &temp){
    if (l >= r)
    {
        return ;
    }
    int mid = l + (r - l) / 2;
    merge_sort(nums, l, mid, temp);
    merge_sort(nums, mid+1, r, temp);
    
    // merge l->mid, and mid+1->r
    int p1 = l, p2=mid+1, i=l;
    while(p1 <= mid && p2 <= r)
    {
        temp[i++] = (nums[p1]<=nums[p2])?nums[p1++]:nums[p2++];
    }
    if(p1 <= mid)
    {
        temp[i++] = nums[p1++];
    }
    if(p2 <= r)
    {
        temp[i++] = nums[p2++];
    }
    for(i = l; i <= r; i++)
    {
        nums[i] = temp[i];
    }
}

int main()
{
    vector<int> nums ={1,3,5,2,4,8,7,6,8};
    vector<int> temp(nums.size());
    merge_sort(nums, 0, nums.size() - 1, temp);
    for (int i = 0 ; i < nums.size() ; i++)
    {
        cout<<nums[i]<<" ";
    }
}