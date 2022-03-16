class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int x, y;
        x = coordinates[0] - 'a';
        y = coordinates[1] - '1';
        if ((x + y) % 2) return true;
        return false;
    }
};