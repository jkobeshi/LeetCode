class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t sum = 0, bit = 31;
        while (n != 0){
            if (n & 1 == 1){
                sum += pow(2, bit);
            }
            n >>= 1; bit--;
        }
        return sum;
    }
};