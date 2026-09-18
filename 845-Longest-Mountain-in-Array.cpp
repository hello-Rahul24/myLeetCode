class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        // int n = arr.size();
        // if(n < 3)return 0;
        // vector<int> dp(n,1);
        // vector<int> dp2(n,1);
        // for(int i = 1 ; i < n ; i++){
        //     for(int j = 0 ; j < i; j++){
        //         if(dp[i] < 1 + dp[j] && arr[j] < arr[i]){
        //             dp[i] = 1 + dp[j];
        //         }
        //     }
        // }
        // int maxlen = 0;
        // for(int i = n-1 ; i >= 0 ;i--){
        //     for(int j = n-1; j > i ;j--){
        //         if(dp2[i] < 1 + dp2[j] && arr[j] < arr[i]){
        //             dp2[i] = 1 + dp2[j];
        //         }
        //     }
        //     if(dp2[i] > 1 && dp[i] >1){
        //         maxlen = max(maxlen, dp[i]+dp2[i]-1);
        //     };
        // }
        // return maxlen > 2 ? maxlen : 0;
        // THIS QUESTION IS ASKING ABOUT SUBARRAY WHICH MEANS CONTAGIOUS MEANS CANT SKIP ELEMENT
        int n = arr.size();
        if(n < 3)return 0;
        vector<int> dp(n,1);
        vector<int> dp2(n,1);
        for(int i = 1 ; i < n ; i++){
            if(arr[i] > arr[i-1]){
                dp[i] = dp[i-1] + 1;
            }
        }
        for(int i = n-2; i >= 0 ; i--){
            if(arr[i] > arr[i+1]){
                dp2[i] = 1+dp2[i+1];
            }
        }
        int maxlen = 0;
        for(int i = 0 ; i < n ; i++){
            if(dp[i] > 1 && dp2[i] > 1){
                maxlen = max(maxlen , dp[i]+dp2[i]-1);
            }
        }
        return maxlen;
    }
};