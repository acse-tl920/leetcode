#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        bool change = false;
        for(int i = 1; i < n ; i++)
        {
            if(nums[i-1] > nums[i])
            {
                if(change) return false;
                change = true;
                if(!((i-1 == 0) || (nums[i-2] <= nums[i]) || (i == n-1) || nums[i-1]<=nums[i+1]))
                    return false;
            }
        }
        return true;
    }
};