class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0, maxR = nums[0];
        while(i < nums.size() && i <= maxR){
            maxR = max(maxR, i + nums[i]);
            ++i;
        }
        return maxR >= nums.size() - 1;
    }
};