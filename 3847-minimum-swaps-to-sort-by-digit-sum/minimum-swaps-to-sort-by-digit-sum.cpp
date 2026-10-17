class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; ++i) {
            int d_sum = 0, temp = nums[i];
            while (temp > 0) {
                d_sum += temp % 10;
                temp /= 10;
            }
            arr[i] = {d_sum, nums[i]};
        }
        
        vector<pair<int, int>> sorted_arr = arr;
        sort(sorted_arr.begin(), sorted_arr.end());
        
        vector<bool> vis(n, false);
        int cycles = 0;
        
        for (int i = 0; i < n; ++i) {
            if (vis[i] || sorted_arr[i] == arr[i]) continue;
            
            int j = i;
            int count = 0;
            while (!vis[j]) {
                vis[j] = true;
                
                auto target = arr[j];
                auto it = lower_bound(sorted_arr.begin(), sorted_arr.end(), target);
                int idx = it - sorted_arr.begin();
                while (idx < n && sorted_arr[idx] == target && sorted_arr[idx] == arr[idx]) {
                    idx++;
                }
                j = idx;
                count++;
            }
            if (count > 0) {
                cycles += (count - 1);
            }
        }
        return cycles;
    }
};