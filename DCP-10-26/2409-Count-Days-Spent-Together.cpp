class Solution {
public:
    int count_days(string s){
        int month = (s[0]-'0')*10+(s[1]-'0');
        int date = (s[3]-'0')*10+(s[4]-'0');
        /*
        1 ==> 0
        2 ==> 31
        3 ==> 28+31
        4 ==> 31 + 28 + 31
        5 ==> 31 + 28 + 31 + 30
        6 ==> 31 + 28 + 31 + 30 + 31
        7 ==> 31 + 28 + 31 + 30 + 31 + 30
        8 ==> 31 + 28 + 31 + 30 + 31 + 30 + 31
        9 ==> 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31
        10 ==> 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30
        11 ==> 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31
        12 ==> 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30
        */
        // Index 0 represents Month 1 (January), Index 11 represents Month 12 (December)
        int daysPast[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
        return daysPast[month -1]+ date;

    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int maxi = max(count_days(arriveAlice), count_days(arriveBob));
        int mini = min(count_days(leaveAlice), count_days(leaveBob));
        return mini >= maxi ? mini - maxi + 1 : 0;
    }
};
/*
        # ----- alice ------- #
             #--bob---#

       this side max       this side min
       min > max
*/