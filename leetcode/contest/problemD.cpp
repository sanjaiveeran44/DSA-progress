class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int val) {
        vector<int> balance = {0};
        int score = 0;
        long long totalCount = 0;

        for(int num: nums){
            score += (num == val ? 1:-1);

            int pos = lower_bound(balance.begin(),balance.end(), score) - balance.begin();

            totalCount += pos;
            balance.insert(balance.begin() + pos,score);
        }
        return totalCount;
    }
};