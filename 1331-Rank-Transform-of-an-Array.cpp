class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
       vector<int>temp = arr;
       sort(temp.begin(),temp.end());
       unordered_map<int,int> mp;
        int r = 1;
    for(auto it :temp){
        if(!mp.count(it)){
            mp[it] = r;
            r++;
        }
    }
    for(auto &it : arr){
        it = mp[it];
    }
    return arr;
    }
};