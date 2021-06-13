#include "main.h"

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        // lower bound if cannot be sqrt
        // range is 1 to x
        if(x == 0)
        {
            return 0;
        }
        int l = 1, r = x, mid, sqrt;

        while(l <= r)
        {
            mid = l + (r - l) / 2;
            sqrt = x / mid;
            if(sqrt == mid)
            {
                return mid;
            }
            else if (sqrt > mid)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return r;
    }
};