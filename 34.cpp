#include "main.h"

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty())
        {
            return vector<int>{-1, -1};
        }
        int firstIndex, lastIndex;
        int lower = 0, upper = nums.size() - 1;
        // find lower bound
        while(lower < upper)
        {
            int temp = (lower + upper) / 2;
            if(nums[temp] >= target)
            {
                upper = temp;
            }
            else
            {
                lower = temp + 1;
            }
        }
        firstIndex = lower;

        lower = 0;
        upper = nums.size();
        // find upper bound
        while(lower < upper)
        {
            int temp = (lower + upper) / 2;
            if(nums[temp] <= target)
            {
                lower = temp + 1;
            }
            else
            {
                upper = temp;
            }
            cout<<lower<<" "<<upper<<endl;
        }
        lastIndex = lower - 1;
        if(firstIndex == nums.size() || nums[firstIndex] != target || lastIndex == nums.size() || nums[lastIndex]!= target)
        {
            return vector<int>{-1, -1};
        }
        return vector<int>{firstIndex, lastIndex};
    }
};

int main()
{
    Solution* solution = new Solution();
    vector<int> A{0, 1, 2, 3, 4};
    int target = 2;
    solution->searchRange(A, target);
    delete solution;
}