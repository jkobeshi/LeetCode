class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> dups;
        int left = 0, largest = 0;
        for(int i = 0; i < s.size(); ++i){
            if(dups.find(s[i]) != dups.end()){
                largest = max(largest, i - left);
                while(s[left] != s[i]){
                    dups.erase(s[left]);
                    ++left;
                }
                ++left;
            } dups.insert(s[i]);
        } return max(largest, (int)s.size() - left);
    }
};
