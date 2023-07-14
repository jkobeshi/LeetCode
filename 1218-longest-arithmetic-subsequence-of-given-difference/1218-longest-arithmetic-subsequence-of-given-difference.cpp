class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> m;
        int maxx = 0;
        for(int i = 0;  i < arr.size(); ++i){
            if(m.find(arr[i] - difference) == m.end()){
                m[arr[i]] = 1;
            }
            else{
                m[arr[i]] = m[arr[i] - difference] + 1;
            }
            maxx = max(maxx, m[arr[i]]);
        }
        return maxx;
    }
};