class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i = 0, j = 0, dir = 0;
        int u = -1, l = -1, d = matrix.size(), r = matrix[0].size(); 
        vector<int> res;
        while(res.size() < matrix.size() * matrix[0].size()){
            res.push_back(matrix[j][i]);
            if(dir == 0){
                if(i + 1 >= r){
                    u += 1;
                    ++j;
                    dir = 1;
                }
                else ++i;
            }
            else if(dir == 1){
                if(j + 1 >= d){
                    r -= 1;
                    --i;
                    dir = 2;
                }
                else ++j;
            }
            else if(dir == 2){
                if(i - 1 <= l){
                    d -= 1;
                    --j;
                    dir = 3;
                }
                else --i;
            }
            else {
                if(j - 1 <= u){
                    l += 1;
                    ++i;
                    dir = 0;
                }
                else --j;
            }
        }
        return res;
    }
};