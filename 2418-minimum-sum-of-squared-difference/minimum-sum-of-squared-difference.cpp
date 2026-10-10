class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<long long> diff(n);
        long long total_k = (long long)k1 + k2;
        long long initial_sum = 0;
        
        for (int i = 0; i < n; ++i) {
            diff[i] = abs(nums1[i] - nums2[i]);
            initial_sum += diff[i];
        }
        
        if (initial_sum <= total_k) return 0;
        
        map<long long, long long, greater<long long>> counts;
        for (int i = 0; i < n; ++i) {
            if (diff[i] > 0) {
                counts[diff[i]]++;
            }
        }
        
        while (total_k > 0 && !counts.empty()) {
            auto it = counts.begin();
            long long val = it->first;
            long long count = it->second;
            counts.erase(it);
            
            auto next_it = counts.begin();
            long long next_val = counts.empty() ? 0 : next_it->first;
            
            long long diff_val = val - next_val;
            long long total_reduce = diff_val * count;
            
            if (total_k >= total_reduce) {
                total_k -= total_reduce;
                if (!counts.empty()) {
                    counts[next_val] += count;
                }
            } else {
                long long steps = total_k / count;
                long long rem = total_k % count;
                
                counts[val - steps] += count - rem;
                counts[val - steps - 1] += rem;
                total_k = 0;
            }
        }
        
        long long ans = 0;
        for (auto& p : counts) {
            ans += p.second * p.first * p.first;
        }
        return ans;
    }
};