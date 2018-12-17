#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i,j;
        i=0;
        j=0;
        double result;
        int temp1,temp2;
        vector<int> New;
        while(i!=nums1.size()&&j!=nums2.size())
        {
            temp1=nums1[i];
            temp2=nums2[j];
            if(temp1<temp2){
                New.push_back(temp1);
                i++;
            }
            else if(temp1>temp2)
            {
                New.push_back(temp2);
                j++;
            }
            else if(temp1==temp2)
            {
                New.push_back(temp1);
                New.push_back(temp2);
                i++;
                j++;
            }
        }
        if(i!=nums1.size())
        {
            for(i;i<nums1.size();i++)
                New.push_back(nums1[i]);
        }
        else if(j!=nums2.size())
        {
            for(j;j<nums2.size();j++)
                New.push_back(nums2[j]);
        }
        int total=nums1.size()+nums2.size();
        if(total%2==0)//Å¼Êý
            result=(double)(New[total/2]+New[total/2-1])/2;
        else
            result=(double)New[(int)(total/2)];
        return result;
    }
};
