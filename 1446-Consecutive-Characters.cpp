class Solution {
public:
    int maxPower(string s) {
        int power = 1;
        int count = 1;
        int firstchar = s[0];
        for(int i = 1;i < s.size(); i++){
            if(s[i] == firstchar){
                count ++;
                power = max(power, count);
            }else{
                firstchar = s[i];
                count = 1;
            }
        }
        return power;
    }
};