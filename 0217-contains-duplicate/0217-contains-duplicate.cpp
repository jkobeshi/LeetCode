class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int maxx = nums[0];
        for(int i = 1; i < nums.size(); ++i)
            maxx = max(maxx, abs(nums[i]));
        vector<bool> set((maxx + 1) * 2);
        for(int i = 0; i < nums.size(); ++i){
            int val = nums[i];
            if(val < 0) val = maxx + abs(val);
            if(set[val]) return 1;
            set[val] = 1;
        }
        return 0;
    }
};