#include "main.h"

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int flowerbedSize = flowerbed.size();
        int i = 0;
        int num =0;
        if(flowerbedSize == 1)
        {   
            if(flowerbed[0] == 0)
                num = 1;
            else
                num =0;
            return (num>=n)?true:false;
        }
        while(i < flowerbedSize)
        {
            if(flowerbed[i] == 0)
            {
                if(((i == 0) && (flowerbed[i+1]==0)) || ((i == flowerbedSize-1) &&  (flowerbed[i-1]==0)) || ((i>0)&&(i<flowerbedSize-1)&&(flowerbed[i-1]==0) && (flowerbed[i+1]==0)))
                {
                    flowerbed[i] = 1;
                    num++;
                }
            }
                i++;
        }
        return (num==n)?true:false;
    }
};

int main()
{
    Solution solution;
    vector<int> flowerbed = {0,0,1,0,0};
    cout<<solution.canPlaceFlowers(flowerbed, 1);
}