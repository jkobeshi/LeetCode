class KthLargest {
private:
    int kth;
    priority_queue<int, vector<int>, greater<int>> que;
public:
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        for(int i = 0; i < nums.size(); ++i){
            que.push(nums[i]);
            if(que.size() > k){
                que.pop();
            }
        }

        // sort(nums.begin(), nums.end(), greater<int>());
        // k = min(k, int(nums.size()));
        // for(int i = 0; i < k; ++i){
        //     que.push(nums[i]);
        // }
    }
    
    int add(int val) {
        que.push(val);
        if(que.size() > kth){
            que.pop();
        }
        return que.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */