class Solution {
public:
    int robbing(vector<int>& nums){
        vector<int> robber;
        int MaxS = 0;
        robber.push_back(nums[0]);
        robber.push_back(max(nums[0], nums[1]));
        MaxS = max(robber[0], robber[1]);
        for(int i = 2; i < nums.size() - 1; ++i){
            int first = robber[i - 2];
            int second = 0;
            if(i - 3 >= 0){
                second = robber[i - 3];
            }
            robber.push_back(max(first, second) + nums[i]);
            if(robber.back() > MaxS){
                MaxS = robber.back();
            }
        }
        return MaxS;
    }
    int rob(vector<int>& nums){
        if(nums.size() == 1){
            return nums[0];
        }
        if(nums.size() == 2){
            return max(nums[0], nums[1]);
        }
        vector<int> newNums;
        for(int i = nums.size() - 1; i >= 0; --i){
            newNums.push_back(nums[i]);
        }
        return max(robbing(nums), robbing(newNums));
    }

};