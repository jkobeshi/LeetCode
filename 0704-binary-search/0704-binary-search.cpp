class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0){
            return -1;
        }
        if(nums.size() == 1){
            if(nums[0] == target){
                return 0;
            }
            else{
                return -1;
            }
        }
        int mid = nums.size() / 2;
        if(target == nums[mid]){
            return mid;
        }
        if(target > nums[mid]){
            vector<int> temp(nums.begin() + mid, nums.end());
            int res = search(temp, target);
            if(res == -1){
                return res;
            }
            return mid + res;
        }
        else{
            vector<int> temp(nums.begin(), nums.begin() + mid);
            return search(temp, target);
        }
    }
};