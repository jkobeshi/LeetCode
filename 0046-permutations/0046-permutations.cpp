class Solution {
public:
    vector<vector<int>> permutations;
    
    void dfs(vector<int>& nums, int k){
        if (k == nums.size()) {
            permutations.push_back(nums);
            return;
        }
        for(int i = k; i < nums.size(); ++i){
            swap(nums[i], nums[k]);
            dfs(nums, k + 1);
            swap(nums[i], nums[k]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        dfs(nums, 0);
        return permutations;
    }
};