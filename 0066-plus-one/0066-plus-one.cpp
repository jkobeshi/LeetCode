class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() -1;
        int plusOne = 1;
        while(plusOne > 0){
            if(i < 0){
                digits.insert(digits.begin(), 1);
                break;
            }
            digits[i] += plusOne;
            plusOne = 0;
            if(digits[i] > 9){
                plusOne = 1;
                digits[i] = digits[i] % 10;
                --i;
            }
        }
        return digits;
    }
};