class Solution {
public:
    string reorganizeString(string s) {
        int freq[26] = {0};
        //count frequency
        for(char ch : s){
            freq[ch-'a']++;
        }
        //count maxfreq
        int maxfreq = 0;
        for(auto it: freq){
            if(it > maxfreq)maxfreq = it;
        }
        // if invalid
        if(maxfreq > ((s.size()+1)/2))return "";

        //define pq
        priority_queue<pair<int,char>>pq;

        for(int i = 0 ; i < 26 ; i++){
            if(freq[i] > 0){
                char ch = 'a' + i;
                pq.push({freq[i], ch});
            }
        }

        string result = "";
        //this is important condition
        while(pq.size() >=2){
            auto firstel = pq.top();
            pq.pop();
            auto secondel = pq.top();
            pq.pop();
            result += firstel.second;
            result += secondel.second;
            if(firstel.first - 1  > 0){
            pq.push({firstel.first - 1,firstel.second});
            }
            if(secondel.first - 1  > 0){
            pq.push({secondel.first - 1,secondel.second});
            }
        }
        if(!pq.empty()){
            result += pq.top().second;
        }

        return result;
    }
};