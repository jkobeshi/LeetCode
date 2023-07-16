class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> st;
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                if(board[i][j] != '.'){
                    string r = to_string(board[i][j]) + "row" + to_string(i);
                    string c = to_string(board[i][j]) + "col" + to_string(j);
                    string b = to_string(board[i][j]) + "box" + to_string((j / 3)) + to_string((i/3));
                    if(st.find(r) != st.end() || 
                        st.find(c) != st.end() ||
                        st.find(b) != st.end()) return false;
                    st.insert(r);
                    st.insert(c);
                    st.insert(b);
                }
            } 
        } return true;
    }
};