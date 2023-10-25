class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        while(i >= 0 && s[i] == ' ') {--i; s.pop_back();}
        while(i >= 0 && s[i] != ' ') --i;
        return s.size() - i - 1;
    }
};