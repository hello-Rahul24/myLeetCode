class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;
        
        for(auto& val : st){
            //if it is not the starting point
            if(st.count(val-1)){
                continue;
            }
            int num = val;
            int count = 1;
            while(st.count(num + 1)){
                count ++;
                num ++;
            }
            ans = max(ans, count);

        }
        return ans;
    }
};