# include"main.h"

using namespace std;

class Solution{
public:
    int findKthLargest(vector<int> & nums, int k){
        int l = 0, r = nums.size() - 1;
        int pivot = nums.size() - k, pivotIndex = nums.size() - k;
        while(l < r)
        {
            int mid = quickSelection(nums, l, r);
            if(mid == pivot)
            {
                return nums[mid];
            }
            else if (mid < pivot)
            {
                l = mid + 1;
            }
            else if (mid > pivot)
            {
                r = mid - 1;
            }
        }
        return nums[l];
    }
    int quickSelection(vector<int> & nums, int l, int r)
    {
        int p = l + rand() % (r - l + 1);
        swap(nums[p], nums[r]);
        int i = l + 1, j = r;
        while(1)
        {
            while(j > l && nums[j] >= nums[l])
            {
                j--;
            }

            while(i < r && nums[i] <= nums[l])
            {
                i++;
            }

            if(i >= j)
            {
                break;
            }
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        int temp = nums[l];
        nums[l] = nums[j];
        nums[j] = temp;
        return j;
    }
};

int main()
{
    Solution* solution = new Solution();
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    cout<<solution->findKthLargest(nums, 4);
    delete solution;
}