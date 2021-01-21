# include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long reverse(long long x) {
        long long result=0;
        if (x >= LONG_MAX/2)
            return 0;
        if (x <= LONG_MIN/2)
            return 0;
        if (x > 0)
        {
            long long i=log10(x); //i=2
            long long len = i;
            while( i>=0 )
            {
                long long temp =pow(10, i);
                result += (x / temp) * pow(10, (len - i));
                x = x % temp;
                i--;
            }
        }
        else if (x == 0)
        {
            return 0;
        }
        else if (x < 0)
        {
            long long i=log10(-x); //i=2
            long long len = i;
            if((log2(-x))/2>=31)
            return 0;
            while( i>=0 )
            {
                long long temp =pow(10, i);
                result += x / temp * pow(10, (len - i));;
                x = x % temp;
                i--;
            }
        }
    return result;
    }
};

int main()
{
    Solution solution;
    long long temp = solution.reverse(1534236469);
    cout << temp;
}