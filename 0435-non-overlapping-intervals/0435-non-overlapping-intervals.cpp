class Solution {
public:
    static bool mySort(vector<int>& l, vector<int>& r){
        return l[0] < r[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), mySort);
        int count = 0;
        for(int i = 0; i < intervals.size() - 1; ++i){
            if (intervals[i][1] > intervals[i+1][0]) {
                if (intervals[i][1] < intervals[i+1][1]) {
                    intervals[i+1] = intervals[i];
                }
                ++count;
            }
        }
        return count;
    }
};