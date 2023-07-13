class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(int i = 0; i < strs.size(); ++i){
            string set = "00000000000000000000000000";
            for(int j = 0; j < strs[i].size(); ++j)
                set[strs[i][j] - 'a']++;
            m[set].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for(auto it = m.begin(); it != m.end(); ++it)
            res.push_back(it->second);
        return res; 
    }
};