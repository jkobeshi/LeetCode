class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.empty() || newInterval[1] < intervals[0][0]){
            intervals.insert(intervals.begin(), newInterval);
        }
        for(int i = 0; i < intervals.size(); ++i){
            if(newInterval[0] > intervals[i][1] && 
                ((i + 1) >= intervals.size() || newInterval[1] < intervals[i + 1][0])){
                    intervals.insert(intervals.begin() + i + 1,  newInterval);
                    break;
            }
            else if(newInterval[1] >= intervals[i][0] && newInterval[0] <= intervals[i][1]){
                intervals[i][0] = min(newInterval[0], intervals[i][0]);
                int k = i + 1;
                while(k < intervals.size() && 
                    (newInterval[1] >= intervals[k][0])){
                        ++k;
                }
                intervals[i][1] = max(newInterval[1], intervals[k - 1][1]); 
                if(k > i + 1){
                    intervals.erase(intervals.begin() + i + 1, intervals.begin() + k);
                }
                break;
            }
        }
        return intervals;
    }
};