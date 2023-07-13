class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        vector<vector<int>> buck(nums.size());
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i) m[nums[i]]++;
        for(auto it = m.begin(); it != m.end(); ++it)
            buck[it->second - 1].push_back(it->first);
        for(int i = buck.size() - 1; i >= 0; --i){
            for(int j = 0; j < buck[i].size(); ++j){
                res.push_back(buck[i][j]);
                --k;
                if(k == 0) return res;
            }
        }
        return res;
    }
};