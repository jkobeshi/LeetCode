class Solution {
public:
    int m, n;
    vector<vector<char>> PorA;
    vector<vector<int>> res;

    void markPacific(vector<vector<int>> &heights, vector<int> cord){
        PorA[cord[0]][cord[1]] = 'P';
        
        if (cord[0] + 1 < n){
            if(heights[cord[0] + 1][cord[1]] >= heights[cord[0]][cord[1]] &&
                    PorA[cord[0] + 1][cord[1]] == 'N'){
                markPacific(heights, {cord[0] + 1, cord[1]});
            }
        }
        if (cord[0] - 1 >= 0){
            if(heights[cord[0] - 1][cord[1]] >= heights[cord[0]][cord[1]] &&
                    PorA[cord[0] - 1][cord[1]] == 'N'){
                markPacific(heights, {cord[0] - 1, cord[1]});
            }
        }
        if (cord[1] + 1 < m){
            if(heights[cord[0]][cord[1] + 1] >= heights[cord[0]][cord[1]] &&
                    PorA[cord[0]][cord[1] + 1] == 'N'){
                markPacific(heights, {cord[0], cord[1] + 1});
            }
        }
        if (cord[1] - 1 >= 0){
            if(heights[cord[0]][cord[1] - 1] >= heights[cord[0]][cord[1]] &&
                    PorA[cord[0]][cord[1] - 1] == 'N'){
                markPacific(heights, {cord[0], cord[1] - 1});
            }
        }
    }

    void markAtlantic(vector<vector<int>> &heights, vector<int> cord){
        if (PorA[cord[0]][cord[1]] == 'P'){
            PorA[cord[0]][cord[1]] = 'B';
            res.push_back(cord);
        }
        else{
            PorA[cord[0]][cord[1]] = 'A';
        }
        if (cord[0] + 1 < n){
            if(heights[cord[0] + 1][cord[1]] >= heights[cord[0]][cord[1]] &&
                    (PorA[cord[0] + 1][cord[1]] == 'N' || PorA[cord[0] + 1][cord[1]] == 'P')){
                markAtlantic(heights, {cord[0] + 1, cord[1]});
            }
        }
        if (cord[0] - 1 >= 0){
            if(heights[cord[0] - 1][cord[1]] >= heights[cord[0]][cord[1]] &&
                    (PorA[cord[0] - 1][cord[1]] == 'N' || PorA[cord[0] - 1][cord[1]] == 'P')){
                markAtlantic(heights, {cord[0] - 1, cord[1]});
            }
        }
        if (cord[1] + 1 < m){
            if(heights[cord[0]][cord[1] + 1] >= heights[cord[0]][cord[1]] &&
                    (PorA[cord[0]][cord[1] + 1] == 'N' || PorA[cord[0]][cord[1] + 1] == 'P')){
                markAtlantic(heights, {cord[0], cord[1] + 1});
            }
        }
        if (cord[1] - 1 >= 0){
            if(heights[cord[0]][cord[1] - 1] >= heights[cord[0]][cord[1]] &&
                    (PorA[cord[0]][cord[1] - 1] == 'N' || PorA[cord[0]][cord[1] - 1] == 'P')){
                markAtlantic(heights, {cord[0], cord[1] - 1});
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {    
        m = heights[0].size();
        n = heights.size();        
        PorA.resize(heights.size(), vector<char>(heights[0].size(), 'N'));
        for (int i = 0; i < m; ++i){
            if(PorA[0][i] == 'N'){
                markPacific(heights, {0, i});
            }
        }
        for (int i = 1; i < n; ++i){
            if(PorA[i][0] == 'N'){
                markPacific(heights, {i, 0});
            }
        }
        for (int i = 0; i < m - 1; ++i){
            if(PorA[n-1][i] == 'N' || PorA[n-1][i] == 'P'){
                markAtlantic(heights, {n - 1, i});
            }
        }
        for (int i = 0; i < n; ++i){
            if(PorA[i][m-1] == 'N' || PorA[i][m-1] == 'P'){
                markAtlantic(heights, {i, m - 1});
            }
        }
        return res;
    }
};