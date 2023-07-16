class Solution {
public:
    priority_queue<int> que;
    int lastStoneWeight(vector<int>& stones) {
        for(int i = 0; i < stones.size(); ++i){
            que.push(stones[i]);
        }
        while(que.size() > 1){
            int stonex = que.top();
            que.pop();
            int stoney = que.top();
            que.pop();
            if(stonex != stoney){
                que.push(max(stonex, stoney) - min(stonex, stoney));
            }
        }
        if(que.empty()){
            return 0;
        }
        return que.top();
    }
};