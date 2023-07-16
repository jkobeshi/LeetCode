class Solution {
public:
    static bool mySort(const vector<int>& l, const vector<int>& r){
        return l[0] < r[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), mySort);
        vector<vector<int>> res;
        for(int i = 0; i < intervals.size(); ++i){
            int k = i + 1;
            while(k < intervals.size() && intervals[k][0] <= intervals[i][1]){
                intervals[i][1] = max(intervals[i][1], intervals[k][1]);
                ++k;
            }
            res.push_back(intervals[i]);
            i = k - 1;
        }
        return res;
    }
};