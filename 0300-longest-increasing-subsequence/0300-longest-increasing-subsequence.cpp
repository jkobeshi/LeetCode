class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        int maxx = -1;
        for(int i = 0; i < nums.size(); ++i){
            for(int j = i - 1;  j >= 0; --j){
                if (nums[j] < nums[i] && dp[j] > dp[i]){
                    dp[i] = dp[j];
                }
            }
            ++dp[i];
            maxx = max(dp[i], maxx);
        }
        for(int i = 0; i < dp.size(); ++i){
            cout << dp[0] << " ";
        }
        return maxx;
    }
};