class Solution {
public:
    int reverse(int x) {
        int tempX = x;
        x = abs(x);
        long int newX = x % 10;
        x /= 10;
        while(x > 0){
            newX *= 10;
            newX += x%10;
            x/=10;
        }
        if(newX > INT_MAX || newX < INT_MIN) return 0;
        if(tempX < 0){
            newX *= -1;
        }
        return newX;
    }
};