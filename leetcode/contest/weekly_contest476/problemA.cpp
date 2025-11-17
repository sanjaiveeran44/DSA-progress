class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int a = *max_element(nums.begin(),nums.end());
        auto it = find(nums.begin(),nums.end(),a);
        if(it != nums.end()) nums.erase(it);
        int b = *max_element(nums.begin(),nums.end());
        int c = *min_element(nums.begin(),nums.end());
        return a+b-c;
    }
};