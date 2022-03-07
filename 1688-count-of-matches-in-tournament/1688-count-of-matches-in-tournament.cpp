class Solution {
public:
    int numberOfMatches(int n) {
        int count = 0;
        while (n != 0 && n != 1) {
            if (n%2) {
                count += (n-1)/2;
                n = (n-1)/2 + 1;
            } else {
                count += n = n/2;
            }
        }
        return count;
    }
};

// class Solution {
// public:
//     int numberOfMatches(int n) {
//         return n-1;
//     }
// };