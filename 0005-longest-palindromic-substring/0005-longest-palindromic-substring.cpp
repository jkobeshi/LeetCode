class Solution {
public:
    string longestPalindrome(string s) {
        int startInd = 0, palLen = 1; int k, j;
        for(int i = (s.size() / 2) - 1; i >= 0; --i){
            k = i; j = i;
            while(k >= 0 && k < s.size() && s[k] == s[j]){
                --k; ++j;
            }
            if (j - k - 1 > palLen){
                startInd = k + 1;
                palLen = j - k - 1;
            }
            k = i; j = i + 1;
            while(k >= 0 && k < s.size() && s[k] == s[j]){
                --k; ++j;
            }
            if (j - k - 1 >= palLen){
                startInd = k + 1;
                palLen = j - k - 1;
            }
            if((i + 1) * 2 <= palLen){
                break;
            }
        }
        for(int i = s.size() / 2; i < s.size(); ++i){
            int k = i; int j = i;
            while(k >= 0 && k < s.size() && s[k] == s[j]){
                --k; ++j;
            }
            if (j - k - 1 > palLen){
                startInd = k + 1;
                palLen = j - k - 1;
            }
            k = i; j = i + 1;
            while(k >= 0 && k < s.size() && s[k] == s[j]){
                --k; ++j;
            }
            if (j - k - 1 >= palLen){
                startInd = k + 1;
                palLen = j - k - 1;
            }
            if((s.size() - i) * 2 < palLen){
                break;
            }
        }
        return s.substr(startInd, palLen);
    }
};