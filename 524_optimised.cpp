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

        // traverse every word in the dictionary
        for(auto word : dictionary)
        {
            int required = word.length();

            // two pointer, i for s string, j for word
            int i = 0; 
            int j = 0;

            // compare every character in two string
            while(i < s.length() && j < word.length())
            {
                if(s[i] == word[j])
                {
                    i++;
                    j++;
                    required--;
                }
                else
                {
                    i++;
                }
            }
            if(required <= 0)
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