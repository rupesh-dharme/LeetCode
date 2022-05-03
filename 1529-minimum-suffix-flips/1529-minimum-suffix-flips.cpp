class Solution {
public:
    int minFlips(string target) {
        int result = 0, n = target.size();
        for (int i = 0; i < n; i++) {
            if (result % 2 == 0 && target[i] == '1' || result % 2 && target[i] == '0') result++;
        }
        return result;
    }
};

// class Solution { //Incorrect try
// public:
//     int minFlips(string target) {
//         if (count(target.begin(), target.end(), '1') == 0) return 0;
//         int result = 0, n = target.size();
//         bool one = true;
//         for (int i = 0; i < n; i++) {
//             if (one) {
//                 if (target[i] == '1') {
//                     result++;
//                     while (i + 1 < n && target[i+1] == '1') i++;
//                 }
                
//                 one = !one;
//             } else if (!one) {
//                 if (target[i] == '0') {
//                     result++;
//                     while(i + 1 < n && target[i+1] == '0') i++;
//                 }
//                 one = !one;
//             }
//         }
//         return result;
//     }
// };