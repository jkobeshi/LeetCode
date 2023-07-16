class Solution {
public:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fresh = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) fresh++;
            }
        }
        q.push({-1, -1});
        
        int result = -1;

        while (!q.empty()) {
            pair<int, int> ind = q.front();
            q.pop();
            
            if (ind.first == -1) {
                result++;
                if (!q.empty()) q.push({-1, -1});
            } else {
                for (int i = 0; i < dirs.size(); i++) {
                    int x = ind.first + dirs[i][0];
                    int y = ind.second + dirs[i][1];
                    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) continue;
                    if (grid[x][y] == 1) {
                        grid[x][y] = 2;
                        fresh--;
                        q.push({x, y});
                    }
                }
            }
        }
        if (fresh == 0) return result;
        return -1;
    }   
};