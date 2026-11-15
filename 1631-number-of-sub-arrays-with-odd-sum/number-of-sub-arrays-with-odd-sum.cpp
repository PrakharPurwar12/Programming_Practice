class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd_count = 0, even_count = 1;
        int current_sum = 0;
        long long total_subarrays = 0;
        int mod = 1e9 + 7;

        for (int x : arr) {
            current_sum += x;
            if (current_sum % 2 != 0) {
                total_subarrays = (total_subarrays + even_count) % mod;
                odd_count++;
            } else {
                total_subarrays = (total_subarrays + odd_count) % mod;
                even_count++;
            }
        }

        return total_subarrays;
    }
};