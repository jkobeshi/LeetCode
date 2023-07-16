class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> str1(26, 0);
        for(int i = 0; i < s1.size(); ++i)
            str1[s1[i] - 'a']++;
        for(int i = 0; i < s2.size(); ++i){
            vector<int> str2(26, 0);
            int j = i;
            while(j < s2.size() && str1[s2[j] - 'a'] > 0){
                str2[s2[j] - 'a']++;
                if(str1 == str2) return true;
                while (str2[s2[j] - 'a'] > str1[s2[j] - 'a']){
                    str2[s2[i] - 'a']--;
                    ++i;
                }
                ++j;
            }
            i = j;
            if(s2.size() - i < s1.size()) return false;
        }
        return false;
    }
};