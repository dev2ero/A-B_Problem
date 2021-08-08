class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX, maxProfits = 0;
        for(int price : prices) {
            minPrice = min(price, minPrice);
            maxProfits = max(price - minPrice, maxProfits);
        }
        return maxProfits;
    }
};
