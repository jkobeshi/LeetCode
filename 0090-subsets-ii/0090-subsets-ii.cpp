class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int> subset, vector<int> nums){
        res.push_back(subset);
        if(nums.empty()) return;
        while(!nums.empty()){
            subset.push_back(nums.back());
            nums.pop_back();
            dfs(subset, nums);
            while(!nums.empty() && nums.back() == subset.back()){
                nums.pop_back();
            }
            subset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs({}, nums);
        return res;
    }
};