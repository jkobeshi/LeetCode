class Solution {
public:
    vector<vector<int>> res;
    int targ;
    void dfs(vector<int> subset, vector<int> leftOver, int sum){
        if(sum == targ){
            res.push_back(subset);
            return;
        }
        if(leftOver.empty() || sum > targ) return;
        while(!leftOver.empty()){
            subset.push_back(leftOver.back());
            leftOver.pop_back();
            dfs(subset, leftOver, sum + subset.back());
            while(!leftOver.empty() && leftOver.back() == subset.back()){
                leftOver.pop_back();
            }
            subset.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        targ = target;
        sort(candidates.begin(), candidates.end());
        dfs({}, candidates, 0);
        return res;
    }
};