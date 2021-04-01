# include "main.h"

using namespace std;

#include<cmath>
class Solution {
public:
    bool judgeSquareSum(int c) {
        bool flag = false;
        for(int i = 0 ; i <= sqrt(c); i++)
        {
            if(sqrt(c - i*i) == floor(sqrt(c - i*i)))
                return true;
        }
        return false;
    }
};