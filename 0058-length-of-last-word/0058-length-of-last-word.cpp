class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        while(i >= 0 && s[i] == ' ') --i;
        int endInd = i;
        while(i >= 0 && s[i] != ' ') --i;
        return endInd - i;
    }
};