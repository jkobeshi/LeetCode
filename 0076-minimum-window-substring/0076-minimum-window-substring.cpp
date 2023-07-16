class Solution {
public:
    string minWindow(string s, string t) {
        string ans = "";
        unordered_map<char, int> wind;
        for (int i = 0; i < t.size(); ++i){
            if (wind.find(t[i]) == wind.end()){
                wind[t[i]] = 1;
            }
            else{
                wind[t[i]] += 1;
            }
        }
        deque<int> indicies;
        int min = s.size() + 1, ind = s.size() + 1;
        int uniqueCnt = 0;
        for (int i = 0; i < s.size(); ++i){
            if(wind.find(s[i]) != wind.end()){
                indicies.push_back(i);
                wind[s[i]] -= 1;
                if(wind[s[i]] == 0){
                    uniqueCnt += 1;
                }
                if (indicies.size() >= t.size()){
                    while(wind[s[indicies.front()]] < 0){
                        wind[s[indicies.front()]] += 1;
                        indicies.pop_front();
                    }
                }
                if (uniqueCnt == wind.size()){
                    if (indicies.back() - indicies.front() + 1 < min){
                        min = indicies.back() - indicies.front() + 1;
                        ind = indicies.front();
                    }
                }
            }
        }
        if (ind != s.size() + 1){
            ans = s.substr(ind, min);
        }
        return ans;
    }
};