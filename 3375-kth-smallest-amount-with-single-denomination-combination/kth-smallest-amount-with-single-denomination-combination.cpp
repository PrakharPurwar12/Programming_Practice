class Solution {
public:
    long long findKthSmallest(std::vector<int>& coins, int k) {
        int n = coins.size();
        
        auto countMultiples = [&](long long mid) -> long long {
            long long cnt = 0;
            for (int mask = 1; mask < (1 << n); ++mask) {
                long long current_lcm = 1;
                int bits = 0;
                for (int i = 0; i < n; ++i) {
                    if ((mask >> i) & 1) {
                        bits++;
                        current_lcm = std::lcm(current_lcm, (long long)coins[i]);
                        if (current_lcm > mid) break;
                    }
                }
                if (current_lcm <= mid) {
                    if (bits % 2 == 1) {
                        cnt += mid / current_lcm;
                    } else {
                        cnt -= mid / current_lcm;
                    }
                }
            }
            return cnt;
        };

        long long left = 1;
        long long right = (long long)*std::min_element(coins.begin(), coins.end()) * k;
        long long ans = right;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (countMultiples(mid) >= k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};