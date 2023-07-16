class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(int i = 0; i < tokens.size(); ++i){
            if(isdigit(tokens[i][0]) || (tokens[i][0] == '-' && tokens[i].size() > 1)){
                stk.push(stoi(tokens[i]));
            }
            else{
                int num2 = stk.top();
                stk.pop();
                int num1 = stk.top();
                stk.pop();
                int ans;
                if(tokens[i][0] == '+'){
                    ans = num1 + num2;
                }
                if(tokens[i][0] == '*'){
                    ans = num1 * num2;
                }
                if(tokens[i][0] == '-'){
                    ans = num1 - num2;
                }
                if(tokens[i][0] == '/'){
                    ans = num1 / num2;
                }
                stk.push(ans);
            }
        }
        return stk.top();
    }
};