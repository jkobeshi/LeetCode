class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> dp(nums.size());
        int nmax = 1; int nmin = 1;
        int maxx = nums[0];
        for(int i = 0; i < nums.size(); ++i){
            int tempMax = nmax * nums[i];
            int tempMin = nmin * nums[i];
            nmax = max(max(tempMax, tempMin), nums[i]);
            nmin = min(min(tempMax, tempMin), nums[i]);
            maxx = max(nmax, maxx);
        }
        return maxx;
    }
};