class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n <3)return false;
        int peak = 0;
        int down = 0;
        for(int i = 1 ; i < n-1 ; i++){
            if(arr[i] == arr[i-1] || arr[i] == arr[i+1])return false;
            
            if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){
                peak++;
            }else if(arr[i] < arr[i-1] && arr[i] < arr[i+1]){
                down++;
            }
        }
        return down == 0 ? peak == 1 : false;
    }
};