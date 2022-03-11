class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n = plants.size();
        if (n == 0) return 0;
        int distance = 1, initial_capacity = capacity;
        for (int i = 0; i < n; i++) {
            if (plants[i] > capacity) {
                distance += 2*(i-1) + 2;
                capacity = initial_capacity;
            }
            distance++;
            capacity -= plants[i];
        }
        return --distance;
    }
};