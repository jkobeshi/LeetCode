class Solution {
public:
    vector<vector<string>> res;
    void dfs(string& s, int i, vector<string>& part){
        if(i == s.size()){
            res.push_back(part);
            return;
        }
        for(int it = i; it < s.size(); ++it){
            if(isPal(s, i, it)){
                part.push_back(s.substr(i, it - i + 1));
                dfs(s, it + 1, part);
                part.pop_back();
            }
        }
    }
    bool isPal(string str, int i, int j){
        while(i < j){
            if(str[i] != str[j]) return false;
            ++i; --j;
        } return true;
    }

    vector<vector<string>> partition(string s) {
        vector<string> part;
        dfs(s, 0, part);
        return res;
    }
};