class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> m;
        int maxx = 0;
        for(int i = 0;  i < arr.size(); ++i){
            auto it = m.find(arr[i] - difference);
            if(it != m.end())
                m[arr[i]] = it->second + 1;
                maxx = max(maxx, m[arr[i]]);
        }
        return maxx + 1;
    }
};