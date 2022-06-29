class Solution {
public:
    static bool cmp(vector<int> &v1,vector<int> &v2)
    {
        if(v1[0]==v2[0])
            return v1[1]<v2[1];
        return v1[0]<v2[0];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n=people.size(),j,k,pos;
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> ans(n, vector<int>(2,-1));
        for(int i=0;i<n;i++)
        {
            if(i==0 || people[i][0]!=people[i-1][0])
            {
                j=0;
                k=-1;
            }
            for(j;j<n;j++)
            {
                k+=(ans[j][1]==-1);
                if(k==people[i][1])
                {
                    pos=j;
                    break;
                }
            }
            ans[pos][0]=people[i][0];
            ans[pos][1]=people[i][1];
        }
        return ans;
    }
};