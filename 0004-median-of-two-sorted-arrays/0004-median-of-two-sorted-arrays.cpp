class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        bool even = false;
        if((nums1.size() + nums2.size()) % 2 == 0)  even = true;
        int n1 = 0, n2 = 0, med = INT_MIN, prev = INT_MIN;
        while (n1 + n2 <= (nums1.size() + nums2.size()) / 2){
            prev = med;
            if(n1 < nums1.size() && n2 < nums2.size()){
                if (nums1[n1] < nums2[n2]){
                    med = nums1[n1];
                    ++n1;
                }
                else{
                    med = nums2[n2];
                    ++n2;
                }
            }
            else if(n1 < nums1.size()){
                med = nums1[n1];
                ++n1;
            }
            else if (n2 < nums2.size()){
                med = nums2[n2];
                ++n2;
            }
        }
        if(even) return double(med + prev) / 2.0;
        return med;
    }
};