class Solution {
public:
    vector<string> res;
    unordered_map<char, string> phoneMap;
    void dfsNums(string dig, int i, string& comb){
        if (i == dig.size()){
            res.push_back(comb);
            return;
        }
        string combinations = phoneMap[dig[i]];
        for(int it = 0; it < combinations.size(); ++it){
            comb.push_back(combinations[it]);
            dfsNums(dig, i + 1, comb);
            comb.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        string comb;
        phoneMap['2'] = "abc";
        phoneMap['3'] = "def";
        phoneMap['4'] = "ghi";
        phoneMap['5'] = "jkl";
        phoneMap['6'] = "mno";
        phoneMap['7'] = "pqrs";
        phoneMap['8'] = "tuv"; 
        phoneMap['9'] = "wxyz";
        dfsNums(digits, 0, comb);
        return res;
    }
};