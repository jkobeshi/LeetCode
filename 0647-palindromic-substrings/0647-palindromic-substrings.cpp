class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for(int i = 0; i < s.size(); ++i){
            int j = i; int k = i;
            while(j >= 0 && j < s.size() && s[j] == s[k]){
                --j; ++k;
            }
            count += k - i;
            j = i;  k = i + 1;
            while(j >= 0 && j < s.size() && s[j] == s[k]){
                ++count;
                --j; ++k;
            }
        }
        return count;
    }
};