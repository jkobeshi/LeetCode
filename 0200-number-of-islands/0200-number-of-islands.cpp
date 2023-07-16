class Solution {
public:
    void visit(vector<vector<char>>& grid, int i , int j){
        if (i < 0 || i >= grid.size() ||
            j < 0 || j >= grid[0].size() ||
            grid[i][j] == '0'){
                return;
        }
        grid[i][j] = '0';
        visit(grid, i - 1, j);
        visit(grid, i + 1, j);
        visit(grid, i, j - 1);
        visit(grid, i, j + 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == '1'){
                    ++count;
                    visit(grid, i, j);
                }
            }
        }
        return count;
    }
};