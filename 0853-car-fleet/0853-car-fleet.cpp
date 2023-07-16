class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> hrs;
        for (int i = 0; i < position.size(); i++)
            hrs.push_back({position[i], double(target - position[i]) / speed[i]});
        sort(hrs.begin(), hrs.end());

        int res = 0;
        double maxx = 0.0;
        for (int i = position.size() - 1; i >= 0; i--) {
            if (hrs[i].second > maxx) {
                maxx = hrs[i].second;
                res++;
            }
        }
        return res;
    }
};