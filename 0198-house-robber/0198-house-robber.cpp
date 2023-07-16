class Solution {
public:
    int rob(vector<int>& nums) {
        int MaxS = 0;
        vector<int> houses;
        if(nums.size() == 1){
            return nums[0];
        }
        if(nums.size() == 2){
            return max(nums[0], nums[1]);
        }
        houses.push_back(nums[0]);
        houses.push_back(max(nums[0], nums[1]));
        MaxS = max(houses[0], houses[1]);
        for(int i = 2; i < nums.size(); ++i){
            int first = houses[i - 2];
            int second = 0;
            if(i - 3 >= 0){
                second = houses[i - 3];
            }
            houses.push_back(max(first, second) + nums[i]);
            if(houses.back() > MaxS){
                MaxS = houses.back();
            }
        }
        return MaxS;
    }
};