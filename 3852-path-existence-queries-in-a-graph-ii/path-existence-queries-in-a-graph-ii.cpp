class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> vals = nums;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        
        int m = vals.size();
        int max_nxt = 20; 
        vector<vector<int>> up(m, vector<int>(max_nxt));
        
        for (int i = 0; i < m; ++i) {
            auto it = upper_bound(vals.begin(), vals.end(), vals[i] + maxDiff);
            int idx = distance(vals.begin(), it) - 1;
            up[i][0] = idx;
        }
        
        for (int j = 1; j < max_nxt; ++j) {
            for (int i = 0; i < m; ++i) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
        
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (const auto& q : queries) {
            int u = q[0], v = q[1];
            if (u == v) {
                ans.push_back(0);
                continue;
            }
            if (nums[u] == nums[v]) {
                ans.push_back(1);
                continue;
            }
            
            int s_val = min(nums[u], nums[v]);
            int t_val = max(nums[u], nums[v]);
            
            int curr = distance(vals.begin(), lower_bound(vals.begin(), vals.end(), s_val));
            int steps = 0;
            
            for (int j = max_nxt - 1; j >= 0; --j) {
                int nxt = up[curr][j];
                if (vals[nxt] < t_val) {
                    steps += (1 << j);
                    curr = nxt;
                }
            }
            
            int nxt = up[curr][0];
            if (vals[nxt] >= t_val) {
                ans.push_back(steps + 1);
            } else {
                ans.push_back(-1);
            }
        }
        
        return ans;
    }
};