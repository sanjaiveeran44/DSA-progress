class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max = *max_element(nums.begin(),nums.end());
        int req = 0;
        for(int v: nums) req += abs(max-v);
        return req;
    }
};