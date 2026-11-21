class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> orig_adj(n);
        for (int i = 1; i < n; ++i) {
            orig_adj[parent[i]].push_back(i);
        }

        vector<int> new_parent(n, -1);
        vector<int> last_seen(26, -1);

        auto dfs_reparent = [&](auto& self, int u) -> void {
            int c = s[u] - 'a';
            int prev = last_seen[c];
            if (u != 0) {
                new_parent[u] = (prev != -1) ? prev : parent[u];
            }
            last_seen[c] = u;
            for (int v : orig_adj[u]) {
                self(self, v);
            }
            last_seen[c] = prev;
        };

        dfs_reparent(dfs_reparent, 0);

        vector<vector<int>> final_adj(n);
        for (int i = 1; i < n; ++i) {
            final_adj[new_parent[i]].push_back(i);
        }

        vector<int> ans(n, 1);
        auto dfs_size = [&](auto& self, int u) -> int {
            int sz = 1;
            for (int v : final_adj[u]) {
                sz += self(self, v);
            }
            return ans[u] = sz;
        };

        dfs_size(dfs_size, 0);
        return ans;
    }
};