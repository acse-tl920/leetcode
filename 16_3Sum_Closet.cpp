#include "main.h"

using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int result = 100000;
        int n = nums.size();
        int sum;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                for(int k = j+1 ; k< n;k++)
                {
                    if(abs(nums[i]+nums[j]+nums[k]-target)<result)
                    {
                        sum = nums[i]+nums[j]+nums[k];
                        result = abs(nums[i]+nums[j]+nums[k]-target);
                    }
                }
            }
        }
        return sum;
    }
};

int main()
{
    Solution* solution = new Solution();
    vector<int> a= {-1,2,1,-4};
    int target = 1;
    cout<<solution->threeSumClosest(a, target)<<endl;
}