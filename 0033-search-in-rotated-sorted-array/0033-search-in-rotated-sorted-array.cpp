class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        while(i <= j){
            int mid = (j - i) / 2 + i;
            if (nums[mid] == target){
                return mid;
            }
            if(nums[i] > nums[mid]){
                if(nums[j] < target || nums[mid] > target){
                    j = mid - 1;
                }
                else {
                    i = mid + 1;
                }
            }
            else{
                if(nums[i] > target || nums[mid] < target){
                    i = mid + 1;
                }
                else {
                    j = mid - 1;
                }
            }
        }
        return -1;  
    }
};