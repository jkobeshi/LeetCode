class Solution {
public:
    vector<string> res;
    void dfs(int n, string pars, stack<char> stk, int numOp){
        if(pars.size() == n * 2){
            res.push_back(pars);
            return;
        }
        if(!stk.empty()){
            stk.pop();
            dfs(n, pars + ")", stk, numOp);
            stk.push('(');
        }
        if(numOp < n){
            stk.push('(');
            dfs(n, pars + "(", stk, numOp + 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        stack<char> stk;
        dfs(n, "", stk, 0);
        return res;
    }
};