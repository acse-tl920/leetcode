#include"main.h"
class Solution{
public:
    int myAtoi(string s) {
        int length = s.length();
        int sign = 1;
        int flag = 0;
        long long sum = 0;
        int isFirst=0;
        for(int i = 0 ; i < length; i++)
        {
            if(s.at(i) == ' ')
            {
                if(flag == 1)
                    return (int)sign*sum;
                continue;
            }
            else if(s.at(i) == '+')
            {
                if(flag == 0)
                {
                    flag = 1;
                    sign = 1;
                }
                else
                    return (int)sign*sum;
            }
            else if(s.at(i) == '-')
            {
                if(flag == 0)
                {
                    flag = 1;
                    sign = -1;
                }
                else
                    return (int)sign*sum;
            }
            else if((s.at(i)>='0') && (s.at(i)<='9'))
            {
                sum = (sum*10)+(s.at(i) - '0');
                cout<<"sum "<<sum<<endl;
                flag = 1;
                if(sign*sum > INT_MAX)
                    return INT_MAX;
                if(sign*sum < INT_MIN)
                    return INT_MIN;
            }
            else
            {
                    return (int)sign*sum;
            }
            
        }
        return (int)sign*sum;
    }
};