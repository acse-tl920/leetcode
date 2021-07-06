#include "main.h"

using namespace std;

void insertion_sort(vector<int>& nums, int n)
{
    int temp;
    for(int i = 0; i < n ; i++)
    {
        int j = i - 1;
        int k = i;
        while(j >= 0)
        {
            if(nums[j] > nums[k])
            {
                temp = nums[k];
                nums[k] = nums[j];
                nums[j] = temp;
                k=j;
                j--;
            }
            else
            {
                break;
            }
        }
    }
}

int main()
{
    vector<int> nums {1,2,2,3,4,7,0,6,9};
    insertion_sort(nums, nums.size());
    for(int i = 0 ; i < nums.size() ;i++)
    {
        cout<<nums[i]<<" ";
    }
}