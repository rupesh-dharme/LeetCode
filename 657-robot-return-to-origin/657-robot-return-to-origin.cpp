class Solution {
public:
    bool judgeCircle(string moves) {
        int displacementX = 0, displacementY = 0;
        for (auto &move : moves) {
            switch (move) {
                case 'L':
                    displacementX--;
                    break;
                case 'R':
                    displacementX++;
                    break;
                case 'U':
                    displacementY++;
                    break;
                case 'D':
                    displacementY--;
                    break;
            }
        }
        if (!displacementX && !displacementY) return true;
        return false;
    }
};