class Solution {
public:
    int maximumSum(vector<int>& arr) {
        // int n = arr.size();
        // int maxsum = INT_MIN;
        // for(int i = 0 ;i < n ; i++){
        //     int maxisum = INT_MIN;
        //     int currmax = 0;
        //     for(int j = 0 ; j < n ; j++){
        //         if(i == j)continue;
        //         currmax = max(arr[j], currmax+arr[j]);
        //         maxisum = max(maxisum, currmax);
        //     }
        //     maxsum = max(maxsum,maxisum);
        // }
        // int max2sum = INT_MIN;
        // int cur2sum = 0;
        // for(auto it: arr){
        //     cur2sum = max(it, cur2sum + it);
        //     max2sum = max(max2sum, cur2sum);
        // }
        // return max(maxsum, max2sum);
        int ans = arr[0];
        int nodelet = arr[0];
        int onedelet = 0;
        for(int i = 1; i < arr.size(); i++){
            int newNodelet = max(arr[i],nodelet+arr[i]);
            int newonedelet = max(nodelet , onedelet+arr[i]);
            nodelet = newNodelet;
            onedelet = newonedelet;
            ans = max(ans,max(newNodelet,newonedelet));
        }
        return ans;
    }
};