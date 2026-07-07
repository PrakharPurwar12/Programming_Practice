class Solution {
public:
    long long sumAndMultiply(int n) {
        if (n == 0) return 0;
        
        long long x = 0;
        long long multiplier = 1;
        long long sum = 0;
        
        int temp = n;
        while (temp > 0) {
            int digit = temp % 10;
            if (digit != 0) {
                x = digit * multiplier + x;
                multiplier *= 10;
                sum += digit;
            }
            temp /= 10;
        }
        
        return x * sum;
    }
};