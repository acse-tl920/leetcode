#include<main.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        else if(x == 0)
            return true;
        else
        {
            string num = to_string(x);
            int n = num.length();
            int i = 0, j = n-1;
            while(i < j)
            {
                if(num.at(i) == num.at(j))
                {
                    i++;
                    j--;
                }
                else
                {
                    return false;
                }
                
            }
        }
        
            return true;
    }
};