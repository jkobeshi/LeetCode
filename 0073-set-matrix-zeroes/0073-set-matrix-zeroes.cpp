class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> cord;
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = 0; j < matrix[i].size(); ++j){
                if(matrix[i][j] == 0){
                    cord.push_back(pair(i, j));
                }
            }
        }
        for(int i = 0; i < cord.size(); ++i){
            for(int j = 0; j < matrix.size(); ++j){
                matrix[j][cord[i].second] = 0;
            }
            for(int j = 0; j < matrix[0].size(); ++j){
                matrix[cord[i].first][j] = 0;
            }
        }
    }
};