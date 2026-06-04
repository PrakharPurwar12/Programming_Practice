class Solution {
private:
    int getWaviness(int num) {
        if (num < 100) return 0; 
        
        vector<int> digits;
        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }
        
        int waviness = 0;
        int n = digits.size();
        
        for (int i = 1; i < n - 1; i++) {
            if (digits[i] > digits[i - 1] && digits[i] > digits[i + 1]) {
                waviness++;
            }
            else if (digits[i] < digits[i - 1] && digits[i] < digits[i + 1]) {
                waviness++;
            }
        }
        
        return waviness;
    }

public:
    int totalWaviness(int num1, int num2) {
        int totalSum = 0;
        
        for (int i = num1; i <= num2; i++) {
            totalSum += getWaviness(i);
        }
        
        return totalSum;
    }
};