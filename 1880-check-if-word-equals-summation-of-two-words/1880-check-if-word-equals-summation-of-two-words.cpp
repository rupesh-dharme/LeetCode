class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int one = 0, two = 0, three = 0;
        one = toNum(firstWord);
        two = toNum(secondWord);
        three = toNum(targetWord);
        return (one + two) == three;
    }
    
    int toNum(string &word) {
        int num = 0;
        for (auto &ch : word) {
            num *= 10;
            num += ch-'a';
        }
        return num;
    }
};