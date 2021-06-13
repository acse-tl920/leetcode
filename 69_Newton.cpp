#include"main.h"

using namespace std;

class Solution {
public:

    // find out sqrt(lower bound value)
    int mySqrt(int a) {
        // Newton method   
        long x = a;
        while(x * x > a)
        {
            double temp = (double)(x*x - a)/ (double)(2*x);
            x = x - temp;
        }
        return x;   
    }
};

int main()
{
    Solution * solution = new Solution();

    cout<<solution->mySqrt(4);
    delete solution;
}