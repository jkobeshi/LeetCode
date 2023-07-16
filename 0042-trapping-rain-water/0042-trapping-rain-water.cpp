class Solution {
public:
    int trap(vector<int>& height) {
        int max = 0;
        for(int i = 1; i < height.size(); ++i)
            if(height[max] < height[i]) max = i;

        int ans = 0;
        int lMax = 0;
        for(int i = 1; i < max; ++i){
            if(height[lMax] > height[i]) ans += (height[lMax] - height[i]);
            else lMax = i;
        }

        lMax  = height.size() - 1;
        for(int i = height.size() - 1; i > max; --i){
            if(height[lMax] > height[i]) ans += (height[lMax] - height[i]);
            else lMax = i;
        }
        return ans;
    }
};