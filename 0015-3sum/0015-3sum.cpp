class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > 0) return res;
            int j = i + 1, k = nums.size() - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    res.push_back(temp);
                    int it = j + 1;
                    while(it < k && nums[it] == nums[j]) ++it;
                    j = it;
                    
                    it = k - 1;
                    while(it > j && nums[it] == nums[k]) --it;
                    k = it;
                }
                else if(sum < 0) {
                    int it = j + 1;
                    while(it < k && nums[it] == nums[j]) ++it;
                    j = it;
                }
                else {
                    int it = k - 1;
                    while(it > j && nums[it] == nums[k]) --it;
                    k = it;
                }
            }
            int it = i + 1;
            while(it < nums.size() && nums[it] == nums[i]) ++it;
            i = it - 1;
        } return res;
    }
};