class Solution {
public:
    vector<int> partitionLabels(string S) {

        vector<int> partition;
        int n = S.length();
        
        vector<int> lastPosition (26, -1);
        
        for(int i = 0 ; i < n; i++)
            lastPosition[(int)(S[i] - 'a')] = i;


        int first = 0;
        int last = 0;
        for(int i = 0; i < n; i++)
        {
            last = max(last, lastPosition[(int)(S[i]-'a')]);
            if(i == last)
            {
                partition.push_back(last-first+1);
                first = i+1;
            }
        }

        return partition;
    }
};