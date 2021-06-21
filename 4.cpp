#include "main.h"

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size_1 = nums1.size();
        int size_2 = nums2.size();
        if(size_1 > size_2) return findMedianSortedArrays(nums2, nums1);

        // handle exceptional situation
        if(size_1 == 0)
        {
            if(size_2 % 2 == 0)
            {
                return ((double)nums2[size_2/2 - 1] + (double)nums2[size_2/2]) / 2;
            }
            else
            {
                return nums2[size_2/2];
            }
        }

        if(size_2 == 0)
        {
            if(size_1 % 2 == 0)
            {
                return ((double)nums1[size_1/2 - 1] + (double)nums1[size_1/2]) / 2;
            }
            else
            {
                return nums1[size_1/2];
            }
        }

        bool isOdd = true;

        // total number is odd
        if((size_1 + size_2) % 2 != 0)
        {
            isOdd = true;
        }
        else
        {
            isOdd = false;
        }
        int l = 0, r = nums1.size() - 1;
        int mid_1, mid_2;
        int left_1, left_2, right_1, right_2;
        // binary search part
        while(1)
        {
            // r can be negative, in this situation, all is nums2
            if((l+r)<0)
            {
                mid_1 = l+r;
            }
            else
                mid_1 = (l+r)/2;
            mid_2 = (size_1 + size_2) / 2 - (mid_1 + 1) - 1;

            // boundary condition
            left_1 = (mid_1>=0)?nums1[mid_1]:INT_MIN;
            left_2 = (mid_2>=0)?nums2[mid_2]:INT_MIN;

            right_1 = ((mid_1+1)<nums1.size())?nums1[mid_1+1]:INT_MAX;
            right_2 = ((mid_2+1)<nums2.size())?nums2[mid_2+1]:INT_MAX;

            // comparison
            // successfully find out
            if(left_1 <= right_2 && left_2 <= right_1)
            {
                if(isOdd)
                {
                    return min(right_1, right_2);
                }
                else
                {
                    return ((double)max(left_1, left_2) + (double)min(right_1, right_2))/2;
                }
            }

            // we need more in nums2
            else if(left_1 > right_2)
            {
                r = mid_1 - 1;
            }

            // we need more in nums1
            else
            {
                l = mid_1 + 1;
            }
        }
    }
};

int main()
{
    Solution * solution = new Solution();
    vector<int> a{3};
    vector<int> b{1,2};
    cout<<solution->findMedianSortedArrays(a,b)<<endl;
    delete solution;
}