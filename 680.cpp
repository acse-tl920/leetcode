#include "main.h"

using namespace std;

class Solution {
public:
    int count = 0;
    bool validPalindrome(string s) {
        int first = 0;
        int last = s.length()-1;
        while(first <= last)
        {
            if(s.at(first) == s.at(last))
            {
                first++;
                last--;
            }
            else
            {
                if(count == 0)
                {
                    int sublen = last - first;
                    int i = first+1;
                    int j = last - 1;
                    count++;
                    if(validPalindrome(s.substr(i, sublen)))
                    {
                        first++;
                        continue;
                    }
                    else
                    {
                        if(validPalindrome(s.substr(first, sublen)))
                        {
                            --last;
                            continue;
                        }
                        else
                        {
                            return false;
                        }
                    }
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
class Solution {
public:
    int count = 0;
    bool validPalindrome(string s) {
        int first = 0;
        int last = s.length()-1;
        while(first <= last)
        {
            if(s.at(first) == s.at(last))
            {
                first++;
                last--;
            }
            else
            {
                if(count == 0)
                {
                    int sublen = last - first;
                    int i = first+1;
                    int j = last - 1;
                    count++;
                    if(validPalindrome(s.substr(i, sublen)))
                    {
                        return true;
                    }
                    else
                    {
                        if(validPalindrome(s.substr(first, sublen)))
                        {
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                    }
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

int main()
{
    string s = "cbbcc";
    Solution* solution = new Solution();
    cout<<solution->validPalindrome(s)<<endl;
    delete solution;
}