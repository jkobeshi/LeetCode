class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0, j = nums.size() - 1, res = nums[0];
        while(i <= j){
            if(nums[i] < nums[j]) return min(res, nums[i]);
            int mid = i + (j - i) / 2;
            res = min(res, nums[mid]);
            if(nums[mid] >= nums[i]) i = mid + 1;
            else j = mid - 1;
        } return res;
    }
};
