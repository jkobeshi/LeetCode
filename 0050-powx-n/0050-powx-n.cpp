class Solution {
public:
    double myPow(double x, int n) {
        long exp = abs(n);
        double curr = x, res = 1.0;
        for (long i = exp; i > 0; i /= 2) {
            if (i % 2 == 1) res *= curr;
            curr *= curr;
        }
        if (n < 0) return 1.0 / res;
        return res;
    }
};