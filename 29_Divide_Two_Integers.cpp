# include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    long divide(long dividend, long divisor) {
        long result = 0;
        if (dividend > (pow(2,31)-1)|| dividend < pow(-2, 31) || divisor > (pow(2,31)-1) || divisor < pow(-2, 31)){
            result = pow(2,31)-1;
        }
        else{
            dividend = (double)dividend;
            divisor = (double)divisor;
            result = trunc(dividend/divisor);
        }
        if (result > (pow(2,31)-1) || result < pow(-2, 31) )
            result = pow(2,31)-1;
        return result;
    }
};

int main()
{
    Solution solution;
    cout<< solution.divide(2147483647, 2);
}