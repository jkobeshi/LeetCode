class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> grid(text1.size(), vector<int>(text2.size()));
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(text1[i] == text2[j]){
                    if (i > 0 && j > 0){
                        grid[i][j] = 1 + grid[i - 1][j - 1];
                    }
                    else{
                        grid[i][j] = 1;
                    }
                }
                else{
                    int top = 0, left = 0;
                    if (i - 1 >= 0){
                    left = grid[i - 1][j];
                    }
                    if (j - 1 >= 0){
                        top = grid[i][j - 1];
                    }
                    grid[i][j] = max(top, left);
                }
            }
        }
        return grid.back().back();
    }
};