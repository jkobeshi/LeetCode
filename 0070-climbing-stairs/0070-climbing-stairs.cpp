class Solution {
public:
    int climbStairs(int n) {
        vector<int> StairN;
        StairN.push_back(1);
        StairN.push_back(2);
        for(int i = 2; i < n; ++i){
            StairN.push_back(StairN[i - 1] + StairN[i - 2]);
        }
        return StairN[n - 1];
    }
};