class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        m[target - nums[0]] = 0;
        for(int i = 1; i < nums.size(); ++i){
            if(m.find(nums[i]) != m.end()) return {m[nums[i]], i};
            m[target - nums[i]] = i;
        }
        return {};
    }
};