class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int size = nums.size();
        vector<int> leftInc(size,1), rightInc(size,1);

        for(int i = 1;i < size;i ++){
            if(nums[i] >= nums[i-1]){
                leftInc[i] = leftInc[i-1]+1;
            }
            
        }

        for(int j= size-2;j >= 0;j--){
            if(nums[j] <= nums[j+1]){
                rightInc[j] = rightInc[j+1]+1;
            }
        }

        int result = *max_element(leftInc.begin(),leftInc.end());
        for(int k = 0;k < size;k ++){
            int leftPart,rightPart;
            if(k > 0)
                leftPart = leftInc[k-1];
            else
                leftPart = 0;

            if(k+1 < size)
                rightPart = rightInc[k+1];
            else
                rightPart = 0;

            if(k > 0 && k+1 < size && nums[k-1] <= nums[k+1] ){
                result = max(result, leftPart +  rightPart+1);
            }
            result = max(result, max(leftPart+1,rightPart+1));
            
        }
        return result;
    }
};