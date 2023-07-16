class Solution {
public:
    bool find(vector<vector<char>>& board, string word, string pref, int i, int j){
        if(i < 0 || i >= board.size() ||
            j < 0 || j >= board[0].size() ||
            board[i][j] == '!' || pref.size() > word.size()){
                return false;
        }
        char og = board[i][j];
        pref = pref + string(1, og);
        if(pref == word){
            return true;
        }
        if(pref != word.substr(0, pref.size())){
            return false;
        }
        board[i][j] = '!';
        bool ans = false;
        ans = ans || find(board, word, pref, i - 1, j);
        ans = ans || find(board, word, pref, i + 1, j);
        ans = ans || find(board, word, pref, i, j - 1);
        ans = ans || find(board, word, pref, i, j + 1);
        board[i][j] = og;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                if(board[i][j] == word[0]){
                    if(find(board, word, "", i, j)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};