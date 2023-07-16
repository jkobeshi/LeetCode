class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = piles[0];
        for(int i = 1; i < piles.size(); ++i)
            high = max(piles[i], high);
        
        int res = high;
        while(low <= high){
            int k = low + (high - low) / 2;
            long int hr = ceil(double(piles[0]) / k);
            for(int i = 1; i < piles.size(); ++i)
                hr += ceil(double(piles[i]) / k);
            if(hr <= h){
                res = k;
                high = k - 1;
            }
            else
                low = k + 1;
        }
        return res;
    }
};