class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> merged;
        int i = 0;
        int j = 0;

        while(i < n && j < m){
            if(nums1[i] < nums2[j]){
                merged.push_back(nums1[i]);
                i++;
            }else{
                merged.push_back(nums2[j]);
                j++;
            }
        }

        if(i < n){
            while(i < n){ 
                merged.push_back(nums1[i]);
                i++;
            }
        }

        if(j < m){
            while(j < m){ 
                merged.push_back(nums2[j]); 
                j++;
            }
        }

        int len = merged.size();
        double ans = 0.0;

        if(len % 2 == 0){
            ans = ((double)merged[len/2] + (double)merged[(len/2)-1]) / 2.0;
        }else{
            ans = (double)merged[len/2];
        }

        return ans;
    }
};