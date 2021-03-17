#include "main.h"

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int num = 0;
        int ballonNum = points.size();
        if(ballonNum == 1 || ballonNum == 0)
        {
            return ballonNum;
        }
        num = 1;
        sort(points.begin(), points.end(),[](vector<int> &a, vector<int> &b)
        {
            return a[0]<b[0];
        });
        int pre = points[0][0];
        int post = points[0][1];
        int i = 1;
        while(i< ballonNum)
        {
            if(points[i][0]>=pre && points[i][0]<=post)
            {
                if(points[i][1]<=post)
                {
                    pre = points[i][0];
                    post = points[i][1];
                }
                else
                {
                    pre = points[i][0];
                }
            }
            else
            {
                pre = points[i][0];
                post = points[i][1];
                num++;
            }
            i++;
        }
        return num;
    }
};