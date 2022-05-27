class Solution {
public:
    int numberOfSteps(int num) {
        if (num == 0) return 0;
        int steps = 0;
        while (num) {
            steps += (num & 1) ? 2 : 1;
            num >>= 1;
        }
        return steps - 1;
    }
};

// class Solution {
// public:
//     int numberOfSteps(int num) {
//         int steps = 0;
//         while(num) {
//             steps++;
//             num = num%2 ? num-1 : num/2;
//         }
//         return steps;
//     }
// };