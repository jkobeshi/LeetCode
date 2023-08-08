class Solution {
public:
    
    vector<vector<int>> res;
    int tar;
    
    void dfs(vector<int>& candidates, int sum, int start, vector<int>& curr) {
        if (sum > tar) {
            return;
        }
        if (sum == tar) {
            res.push_back(curr);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            curr.push_back(candidates[i]);
            dfs(candidates, sum + candidates[i], i, curr);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        tar = target;
        vector<int> temp;
        dfs(candidates, 0, 0, temp);
        return res;
    }
     
};