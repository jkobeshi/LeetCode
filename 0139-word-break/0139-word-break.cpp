class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words;
        for(int i = 0; i < wordDict.size(); ++i){
            words.insert(wordDict[i]);
        }

        vector<bool> dp(s.size());
        dp[0] = words.find(s.substr(0, 1)) != words.end();
        for(int i = 1; i < s.size(); ++i) {
            for(int j = i - 1; j >= -1; --j){
                if(j == -1 || dp[j]){
                    dp[i] = words.find(s.substr(j + 1, i - j)) != words.end();
                    if(dp[i]){
                        break;
                    }
                }
            }
        }
        for(int i = 0;  i < dp.size(); ++i){
            cout << dp[i] << " "; 
        }
        return dp.back();
    }
};