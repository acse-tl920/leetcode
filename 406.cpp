class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> result;
        sort(people.begin(), people.end(), [](vector<int> &a, vector<int> &b){
           if(a[0] == b[0])
           {
               return a[1]<b[1];
           }
            return a[0]>b[0];
        });
        for(auto x:people)
        {
            result.insert(result.begin()+x[1], x);
        }
        return result;
    }
};