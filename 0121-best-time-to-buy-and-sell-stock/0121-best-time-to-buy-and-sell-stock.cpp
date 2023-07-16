class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, lower = prices[0];
        for(int i = 1; i < prices.size(); ++i){
            ans = max(ans, prices[i] - lower);
            lower = min(lower, prices[i]);
        } return ans;
    }
};