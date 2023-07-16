class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int cost1 = cost[0]; int cost2 = cost[1];
        int total = min(cost[0], cost[1]);
        for(int i = 2; i < cost.size(); ++i) {
            total = min(cost1, cost2) + cost[i];
            cost1 = cost2; cost2 = total;
        } return min(cost1, cost2);
    }
};