class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (const auto& inv : invocations) {
            adj[inv[0]].push_back(inv[1]);
        }

        vector<bool> is_suspicious(n, false);
        vector<int> q = {k};
        is_suspicious[k] = true;

        for (size_t i = 0; i < q.size(); ++i) {
            int u = q[i];
            for (int v : adj[u]) {
                if (!is_suspicious[v]) {
                    is_suspicious[v] = true;
                    q.push_back(v);
                }
            }
        }

        for (const auto& inv : invocations) {
            if (!is_suspicious[inv[0]] && is_suspicious[inv[1]]) {
                vector<int> ans(n);
                for (int i = 0; i < n; ++i) {
                    ans[i] = i;
                }
                return ans;
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (!is_suspicious[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};