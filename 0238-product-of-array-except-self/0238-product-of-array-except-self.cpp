class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        int prod = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            res[i] = prod;
            prod *= nums[i];
        }
        prod = nums.back();
        for(int i = nums.size() - 2; i >= 0; --i){
            res[i] *= prod;
            prod *= nums[i];
        }
        return res;
    }
};