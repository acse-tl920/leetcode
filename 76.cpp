#include"main.h"

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if((s.length() == 0 && t.length() == 0)||(t.length()>s.length()))
        {
            return "";
        }

        map<char, int> dictionary;

        for(int i = 0 ; i < t.length() ; i++)
        {
            dictionary[t[i]]++;
        }

        int required = dictionary.size();
        
        int l = 0, r = 0;

        string result = "";

        int minidx = -1;

        int ansLen = INT_MAX;

        while(r<s.length())
        {
            if(dictionary.find(s[r])!=dictionary.end())
            {
                dictionary[s[r]]--;
                if(dictionary[s[r]] == 0)
                {
                    required--;
                }
            }
            while (required == 0)
            {       
                if(ansLen > r-l+1)
                {
                    minidx = l;
                    ansLen = r - l + 1;
                }
                if(dictionary.find(s[l])!=dictionary.end())
                {
                    dictionary[s[l]]++;
                    if(dictionary[s[l]] == 1)
                    required++;
                }
                l++;
            }
            r++;
        }
        return (minidx==-1)?"":s.substr(minidx, ansLen);
    }
};