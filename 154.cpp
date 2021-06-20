#include "main.h"

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        // find out the one smaller than left and right
        int l = 0, r = nums.size() - 1;
        if(nums.size() == 1)
        {
            return nums[0];
        }
        if(nums.size() == 2)
        {
            return nums[0]<=nums[1]?nums[0]:nums[1];
        }
        int ans = 5000;
        while(l <= r)
        {
            // is the original order
            if(nums[l] < nums[r])
            {
                return nums[l];
            }

            // if the smallest is on the very right
            if(nums[r] < nums[l] && nums[r] < nums[r-1])
            {
                return nums[r];
            }
            int mid = l + (r - l) / 2;
            if(nums[mid] < nums[mid - 1] && nums[mid] <= nums[mid + 1])
            {
                return nums[mid];
            }
            if(nums[mid] == nums[l] && nums[mid] == nums[r])
            {
                ans = ans>nums[mid]?nums[mid]:ans;
                r--;
                l++;
                continue;
            }
            
            if(nums[mid] >= nums[l])
            {
                ans = ans>nums[l]?nums[l]:ans;
                l = mid + 1;
            }
            else
            {
                ans = ans>nums[mid]?nums[mid]:ans;
                r = mid - 1;
            }
        }
        return ans;
    }
};
