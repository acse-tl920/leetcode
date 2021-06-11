#include "main.h"

using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        if(dictionary.size() == 0)
        {
            return "";
        }

        if(s.length() == 0)
        {
            return "";
        }
        
        string result = "";
        int len = 0;
        for(auto word : dictionary)
        {
            int required = word.length();
            int sLeft = 0;
            bool flag = true;
            string temp = s;
            for(int i = 0 ; i < required ; i++)
            {
                string sub = temp.substr(sLeft, temp.length() - sLeft + 1);
                if(sub.find(word[i]) == string::npos)
                {
                    flag = false;
                    continue;
                }
                else
                {
                    string::size_type position = sub.find_first_of(word[i]);
                    sLeft = (int)position+1;
                    // cout<<word<<" "<<position<<" "<<word[i]<<endl;
                    temp = sub;
                }
            }
            if(flag == true)
            {
                if(word.length()>len)
                {
                    len = word.length();
                    result = word;
                }
                if(word.length() == len)
                {
                    result = (word>result)?result:word;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution* s = new Solution();
    string a = "abpcplea";
    string b = "ale";
    string c = "apple";
    string d= "monkey";
    string e = "plea";
    string f = "abpcplaaa";
    string g = "abpcllllll";
    string h = "abccclllpppeeaaaa";
    vector<string> dictionary;
    dictionary.push_back(b);
    dictionary.push_back(c);
    dictionary.push_back(d);
    dictionary.push_back(e);
    dictionary.push_back(f);
    dictionary.push_back(g);
    dictionary.push_back(h);
    cout<<s->findLongestWord(a, dictionary);
}