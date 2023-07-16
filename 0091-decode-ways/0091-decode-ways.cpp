class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0'){
            return 0;
        }
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i < s.size() + 1; ++i){
            if(s[i - 1] != '0'){
                dp[i] += dp[i - 1];
            }
            if(stoi(s.substr(i - 2, 2)) <= 26 && s[i - 2] != '0'){
                dp[i] += dp[i - 2];
            }
        }
        return dp.back();
    }
};