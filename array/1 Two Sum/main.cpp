#include<alogrithm>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> temp;
        int i;
        int front,back;
        int a;
        sort(nums.begin(),nums.end());
        for(i=0;i<nums.size();i++)
        {
            front=i+1;
            back=nums.size()-1;
            while(front<back)
            {
                int sum=nums[front]+nums[back];
                if(sum<-nums[i])
                    front++;
                else if(sum>-nums[i])
                    back--;
                else if(sum==-nums[i])
                {
                    vector<int> t(3,0);
                    t[0]=nums[i];
                    t[1]=nums[front];
                    t[2]=nums[back];
                    temp.push_back(t);
                    while(front<back&&nums[front]==t[1]) front++;
                while(front<back&&nums[back]==t[2]) back--;
                }
            }
            while(i+1<nums.size()&&nums[i+1]==nums[i])
                i++;
        }
        return temp;
    }
};
