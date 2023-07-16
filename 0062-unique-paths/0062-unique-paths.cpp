class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n));
        for(int i = 0; i < n; ++i){
            grid[0][i] = 1;
        }
        for(int i = 1;  i < m; ++i){
            for(int j = 0; j < n; ++j){
                int left = 0;
                if (j > 0){
                    left = grid[i][j - 1];
                }
                grid[i][j] = grid[i - 1][j] + left;
            }
        }
        return grid.back().back();
    }
};