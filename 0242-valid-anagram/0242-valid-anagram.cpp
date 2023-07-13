class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> smap(26);
        vector<int> tmap(26);
        for(int i = 0; i < s.size(); ++i){
            smap[s[i] - 'a']++;
            tmap[t[i] - 'a']++;
        }
        return smap == tmap;
    }
};