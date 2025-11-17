class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int c1 = 0;
        int c2 = 0;
        for(auto c : s){
            if(c == 'a') c1++;
            else c2 ++;
        }
        return abs(c1-c2);
    }
};