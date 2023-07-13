class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        int prod = 1;
        for(int i = 0; i < nums.size(); ++i){
            res[i] = prod;
            prod *= nums[i];
        }
        prod = 1;
        for(int i = nums.size() - 1; i >= 0; --i){
            res[i] *= prod;
            prod *= nums[i];
        }
        return res;
    }
};