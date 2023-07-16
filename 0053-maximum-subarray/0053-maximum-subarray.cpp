class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int high = nums[0], low = nums[0], sum = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            high = max(max(high + nums[i], low + nums[i]), nums[i]);
            low = min(min(high + nums[i], low + nums[i]), nums[i]);
            sum = max(high, sum);
        } return sum;
    }
};