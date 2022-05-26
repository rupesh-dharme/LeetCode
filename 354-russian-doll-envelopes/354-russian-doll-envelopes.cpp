class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(env.begin(), env.end(), [](const vector<int> &a, const vector<int> &b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        vector<int> temp;
        temp.push_back(env[0][1]);
        
        for (int i = 1; i < env.size(); i++) {
            if (env[i][1] > temp.back()) temp.push_back(env[i][1]);
            else {
                int ind = lower_bound(temp.begin(), temp.end(), env[i][1]) - temp.begin();
                temp[ind] = env[i][1];
            }
        }
        
        return temp.size();
    }
};

// class Solution {
//     static bool cmp(vector<int>& a, vector<int>& b){
//         if(a[0]==b[0]) return a[1] > b[1];
//         return a[0] < b[0];
//     }
// public:
//     int maxEnvelopes(vector<vector<int>>& env) {
//         int n = env.size();
        
//         sort(env.begin(), env.end(), cmp);
        
      
//         vector<int> lis;
        
//         for(int i = 0;i<env.size();i++){
//             int ele = env[i][1];
            
//             int idx = lower_bound(lis.begin(), lis.end(), ele) - lis.begin();
            
//             if(idx >= lis.size()) lis.push_back(ele);
//             else lis[idx] = ele;
//         }
        
//         return lis.size();
//     }
// };
