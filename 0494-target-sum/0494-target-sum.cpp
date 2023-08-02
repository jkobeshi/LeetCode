class Solution {
public:
    int count = 0;
    void dfs(vector<int>& nums, int ind, int total, int tar){
        if(ind == nums.size()){
            if(total == tar) ++count;
        }
        else {
            dfs(nums, ind + 1, total + nums[ind], tar);
            dfs(nums, ind + 1, total - nums[ind], tar);
        }
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        dfs(nums, 0, 0, target);
        return count;
    }
};