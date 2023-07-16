class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s; int maxx = 0;
        for(int i : nums) s.insert(i);
        for(auto it = s.begin(); it != s.end(); ++it){
            if(s.find(*it - 1) == s.end()){
                int start = *it + 1;
                while(s.find(start) != s.end()) ++start;
                maxx = max(maxx, start - *it);
            }
        } return maxx;
    }
};