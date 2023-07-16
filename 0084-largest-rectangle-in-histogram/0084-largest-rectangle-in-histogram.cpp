class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxx = 0;
        stack<pair<int, int>> stk;
        for(int i = 0; i < heights.size(); ++i){
            int ind = i;
            while(!stk.empty() && stk.top().first > heights[i]){
                maxx = max(maxx, stk.top().first * (i - stk.top().second));
                ind = stk.top().second; stk.pop();
            } stk.push({heights[i], ind});
        }
        for (; !stk.empty(); stk.pop())
            maxx = max(maxx, stk.top().first * ((int)heights.size() - stk.top().second));
        return maxx;
    }
};