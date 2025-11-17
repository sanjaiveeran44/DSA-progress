class Solution {
public:
    long long countDistinct(long long n) {
        string digits = to_string(n);
        int len = digits.size();
        long long result = 0;
        long long pow9 = 1;
        for(int sz = 1;sz < len;sz ++){
            pow9 *= 9;
            result += pow9;
        }

        for(int i = 0;i < len;i ++){
            int digit = digits[i] - '0';
            int rem = len - i - 1;

            if(digit > 0){
                int options = digit - 1;
                if(rem > 0){
                    result += options * pow9power(rem);
                }else{
                    result += options;
                }
            }

            if(digit == 0) break;
            if(i == len - 1) result++;
        }
        return result;
    }
private:
    long long pow9power(int k){
        long long val = 1;
        while(k--) val *= 9;
        return val;
    }
};