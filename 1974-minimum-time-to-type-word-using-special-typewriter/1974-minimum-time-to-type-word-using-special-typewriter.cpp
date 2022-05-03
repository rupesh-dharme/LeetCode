class Solution {
public:
    int minTimeToType(string word) {
        int n = word.size();
        int time = n;
        for (int i = 0; i < n; i++) {
            int diff = abs(word[i] - (i ? word[i-1] : 'a'));
            time += min (diff, 26 - diff);
        }
        return time;
    }
};