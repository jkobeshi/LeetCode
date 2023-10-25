class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int ind = 0;
        bool pre = true;
        while(pre){
            if(ind >= strs[0].size()) break;
            char fir = strs[0][ind];
            for(int i = 1; i < strs.size(); ++i){
                if(ind >= strs[i].size() || strs[i][ind] != fir){
                    pre = false;
                    break;
                }
            }
            if(pre) ++ind;
        }
        return strs[0].substr(0, ind);
    }
};