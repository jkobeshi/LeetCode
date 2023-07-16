class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int> subset, vector<int> leftOver){
        res.push_back(subset);
        if(leftOver.empty()) return;
        while(!leftOver.empty()){
            subset.push_back(leftOver.back());
            leftOver.pop_back();
            dfs(subset, leftOver);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs({}, nums);
        return res;
    }
};