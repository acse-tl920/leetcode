#include"main.h"

using namespace std;

void selection_sort(vector<int> &nums, int n)
{
    for (int i = 0 ; i < n - 1 ; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n ; j++)
        {
            if(nums[j] < nums[minIndex])
            {
                minIndex = j;
            }
        }
        int temp = nums[i];
        nums[i] = nums[minIndex];
        nums[minIndex] = temp;
    }
}

int main()
{
    vector<int> num = {1,3,5,3,2,5,5,7,8,2,9,1};
    selection_sort(num, num.size());
    for (int i = 0 ; i < num.size() ; i++)
    {
        cout<<num[i]<<" ";
    }
}