class Solution {
public:
    int findGCD(vector<int>& nums) {
        int min_val = nums[0];
        int max_val = nums[0];
        
        for (int num : nums) {
            if (num < min_val) min_val = num;
            if (num > max_val) max_val = num;
        }
        
        return gcd(min_val, max_val);
    }

private:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};