class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> firToSec;
        firToSec[nums[0]] = 0;
        for (int i = 1; i < nums.size(); ++i){
            auto it = firToSec.find(target - nums[i]);
            if (it != firToSec.end()){
                return {i, it->second};
            }
            firToSec[nums[i]] = i;

        }
        for (int i = 1; i < nums.size(); ++i){
            auto it = firToSec.find(target - nums[i]);
            if (it != firToSec.end() && i != it->second){
                return {i, it->second};
            }
        }
        return {};
    }
};