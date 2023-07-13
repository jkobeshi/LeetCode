class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); ++i)
            if(nums[i] == nums[i - 1]) return true;
        return false;
    }
};

// Solution Using Set
// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         unordered_set<int> noDup;
//         noDup.insert(nums[0]);
//         for(int i = 1; i < nums.size(); ++i){
//             if(noDup.find(nums[i]) != noDup.end()) return true;
//             noDup.insert(nums[i]);
//         }
//         return false;
//     }
// };