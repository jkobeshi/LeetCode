class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> noDup;
        while(n != 1){
            if(noDup.find(n) != noDup.end()) return false;
            noDup.insert(n);
            int temp = n, sum = 0;
            while(temp > 0){
                sum += (temp % 10) * (temp % 10);
                temp /= 10;
            } n = sum;
        } return true;
    }
};