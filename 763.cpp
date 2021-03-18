#include"main.h"

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {

 vector<int> partition;

        vector<bool> isExit (26, false);

        vector<string> split;

        int n = S.length();

        int i = 0;

        while(i<n)
        {
            int temp = (int)(S[i]-'a');
            string charS (1, S[i]);
            if(isExit[temp] == false) // not exit before
            {
                split.push_back(charS);
                isExit[temp] = true;
            }
            else
            {
                int key = split.size();
                for(int j = 0 ; j < split.size(); j++)
                {
                    if(split[j].find(S[i]) != string::npos) // find it here, then combine string in split[] from j to split.size() -1
                    {
                        key = j;
                    }
                    if(j>key)
                    {
                        split[key] += split[j];
                    }
                }
                split[key] += charS;
                //then have to resize
                split.resize(key+1);
            }
            i++;
        }
        for(int j =0;j<split.size() ;j++)
        {
            partition.push_back(split[j].length());
            cout<<partition[j]<<" ";
        }

        return partition;
    }
};

int main()
{
    string s ="ababcbacadefegdehijhklij";
    Solution solution;
    solution.partitionLabels(s);
}