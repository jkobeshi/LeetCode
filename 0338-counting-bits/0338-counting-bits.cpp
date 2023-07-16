class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i = 0; i <= n; ++i){
            int cnt = 0, temp = i;
            while (temp != 0){
                if (temp & 1 == 1){
                    ++cnt;
                }
                temp >>= 1;
            }
            res.push_back(cnt);
        }
        return res;
    }
};