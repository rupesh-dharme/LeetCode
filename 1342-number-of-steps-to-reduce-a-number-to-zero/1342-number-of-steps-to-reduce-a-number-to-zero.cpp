class Solution {
public:
    int numberOfSteps(int num) {
        int steps = 0;
        while(num) {
            steps++;
            num = num%2 ? num-1 : num/2;
        }
        return steps;
    }
};