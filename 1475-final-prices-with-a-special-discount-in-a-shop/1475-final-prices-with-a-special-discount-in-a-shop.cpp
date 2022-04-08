class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> result;
        int n = prices.size();
        for (int i = 0; i < n; i++) {
            int price = prices[i];
            for (int j = i+1; j < n; j++) {
                if (prices[j] <= prices[i]) {
                    price -= prices[j];
                    break;
                }
            }
            result.push_back(price);
        }
        return result;
    }
};