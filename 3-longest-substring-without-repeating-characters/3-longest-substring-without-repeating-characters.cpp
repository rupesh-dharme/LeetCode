class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> m;
        
        int n =  s.size(),i=0,j=0,ans =0;
        
        while(j<n){
            m[s[j]]++;
            
            if(m[s[j]]==1) ans = max(ans,(j-i)+1);
            
            else {
                while(s[i]!=s[j]){
                    m[s[i]]--;
                    i++;
                }
                m[s[i]]--;
                i++;
            }
            
            j++;
        }
        
        return ans;
        // int len = 1, l = 0, r = 0, n = s.size();
        // if (n == 0) return 0;
        // vector<int> v(256, -1);
        // while (r < n) {
        //     if (v[s[r]] != -1) {
        //         int i = l;
        //         l = v[s[r]]+1;
        //         for (; i <v[s[r]]; i++) v[s[i]] = -1;
        //     } else {
        //         v[s[r]] = r;
        //         if (r-l+1 > len) {
        //             len = r - l + 1;
        //         }
        //     }
        //     r++;
        // }
        // return len;
    }
};