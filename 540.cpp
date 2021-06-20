#include "main.h"

using namespace std;

class Solution {
public:
    int res = -1;
    void findInRecursion(vector<int>& nums, int l, int r)
    {
        int leftResult = -1, rightResult = -1;
        if(l == r)
        {
            res = nums[l];
            return;
        }
        if(l > r)
            return;
        int mid = l + (r - l ) / 2;
        if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid+1])
        {
            res = nums[mid];
        }
        else
        {
            if(mid % 2 != 0)
            {
                if(nums[mid] == nums[mid + 1])
                {
                    findInRecursion(nums, l, mid-1);
                }
                else
                {
                    findInRecursion(nums, mid+1, r);
                }
            }
            else
            {
                if(nums[mid] == nums[mid + 1])
                {
                    findInRecursion(nums, mid+2, r);
                }
                else
                {
                    findInRecursion(nums, l, mid);
                }
            }
        }
    }
    int singleNonDuplicate(vector<int>& nums) {
        findInRecursion(nums, 0, nums.size() - 1);
        return res;
    }
};

int main()
{
    vector<int> nums = {1,1,2,3,4,4,8,8};
    Solution* solution = new Solution();
    cout<<solution->singleNonDuplicate(nums);
    delete solution;
}