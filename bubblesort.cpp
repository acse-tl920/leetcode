#include "main.h"

using namespace std;

void bubble_sort(vector<int> & nums, int n)
{
    for (int i = 1; i < n-1 ; i++)
    {
        for(int j = n - 1; j >= i; j--)
        {
            if (nums[j] < nums[j-1])
            {
                int temp = nums[j];
                nums[j] = nums[j-1];
                nums[j-1] = temp;
            }
        }
    }
}

int main()
{
    vector<int> nums = {1,3,2,1,4,5,6,2,8,9,2,1};
    bubble_sort(nums, nums.size());
    for(int i = 0 ; i < nums.size() ;i++)
    {
        cout<<nums[i]<<" ";
    }
}