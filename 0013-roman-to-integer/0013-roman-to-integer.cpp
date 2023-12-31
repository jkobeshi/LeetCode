class Solution {
public:
    int LtoI(char c){
        switch(c){
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
        }
        return 0;
    }
    int romanToInt(string s) {
        int pre = LtoI(s[0]);
        int res = pre;
        for(int i = 1; i < s.size(); ++i){
            int cur = LtoI(s[i]);
            if (cur > pre)
                res -= 2 * pre;
            res += cur;
            pre = cur;
        }
        return res;
    }
};