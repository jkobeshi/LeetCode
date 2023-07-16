class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size());
        stack<pair<int, int>> stk;
        for(int i = 0; i < temperatures.size(); ++i){
            int cur = temperatures[i];
            while(!stk.empty() && cur > stk.top().first){
                res[stk.top().second] = i - stk.top().second;
                stk.pop();
            }
            stk.push(pair(cur, i));
        }
        return res;
    }
};