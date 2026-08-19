class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        //here we will keep track of every row ,and keep every resereved seats
        unordered_map<int,unordered_set<int>> reserved;
        for(auto &it : reservedSeats){
            reserved[it[0]].insert(it[1]);
        }
        int ans = (n - reserved.size())*2;
        for(auto &it : reserved){
            int left = true;
            int mid = true;
            int right = true;
            for(int i = 2 ; i <= 5 ; i++){
                if(it.second.count(i)){
                    left = false;
                }
            }
            for(int i = 4 ; i <= 7 ; i++){
                if(it.second.count(i)){
                    mid = false;
                }
            }
            for(int i = 6; i <= 9 ; i++){
                if(it.second.count(i)){
                    right = false;
                }
            }
            if(left && right){
                //it means two group can be seated
                ans += 2;
            }else if(left || mid || right ){
                ans += 1;
            }
        }
        return ans;
    }
};