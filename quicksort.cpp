#include "main.h"

using namespace std;

void quick_sort(vector<int> &nums, int l, int r)
{
    if(l + 1 >= r)
    {
        return;
    }

    int first = l, last = r - 1, pivot = nums[first];
    while(first < last)
    {
        while(first < last && nums[last] >= pivot)
        {
            last--;
        }
         nums[first] =nums[last];
        while(first < last && nums[first] <= pivot)
        {
            first++;
        }
        nums[last] = nums[first];
    }
    nums[first] = pivot;
    
    quick_sort(nums, l, first);
    quick_sort(nums, first+1, r);
}

int main()
{
    vector<int> nums = {10,5,8,12,15,6,3,9,5};
    quick_sort(nums, 0, nums.size());
    for (int i = 0 ; i < nums.size() ; i++)
    {
        cout<<nums[i]<<endl;
    }
}