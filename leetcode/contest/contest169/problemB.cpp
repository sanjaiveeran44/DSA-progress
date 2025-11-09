class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int val) {
        int length = nums.size();
        vector<int> prefix(length+1, 0);

        for(int i = 0;i < length;i ++){
            prefix[i+1] = prefix[i] + (nums[i] == val ? 1:-1);
        }
        int total = 0;

        for(int end = 0;end  <= length; ++end){
            for(int start = 0;start < end;++start){
                if(prefix[end] > prefix[start]){
                    total++;
                }
            }
        }
        return total;
    }
};