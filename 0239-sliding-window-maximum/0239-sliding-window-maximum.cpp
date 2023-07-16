class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 1) return nums;

        vector<int> maxes;
        deque<int> dq;

        for(int i = 0; i < k; ++i){
            while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
        }
        maxes.push_back(nums[dq.front()]);
        for(int i = k; i < nums.size(); ++i){
            while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
            if(dq.front() <= i - k) dq.pop_front();
            maxes.push_back(nums[dq.front()]);
        } return maxes;
    }
};