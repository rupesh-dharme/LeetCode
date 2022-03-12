class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> us;
        for (auto& word: words) {
            string morse_code;
            for (auto& ch : word) morse_code += morse[ch-'a'];
            us.insert(morse_code);
        }
        return us.size();
    }
};