class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        
        vector<vector<pair<int, int>>> adj(n);
        vector<int> edge_costs;
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];
            adj[u].push_back({v, cost});
            edge_costs.push_back(cost);
        }
        
        sort(edge_costs.begin(), edge_costs.end());
        edge_costs.erase(unique(edge_costs.begin(), edge_costs.end()), edge_costs.end());
        
        vector<int> in_degree(n, 0);
        for (int u = 0; u < n; ++u) {
            for (const auto& edge : adj[u]) {
                in_degree[edge.first]++;
            }
        }
        
        vector<int> topo;
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);
            for (const auto& edge : adj[u]) {
                int v = edge.first;
                if (--in_degree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        auto check = [&](int min_cost) -> bool {
            if (!online[0] || !online[n - 1]) return false;
            
            vector<long long> dp(n, -1);
            dp[0] = 0;
            
            for (int u : topo) {
                if (dp[u] == -1 || !online[u]) continue;
                
                for (const auto& edge : adj[u]) {
                    int v = edge.first;
                    int cost = edge.second;
                    
                    if (cost >= min_cost && online[v]) {
                        if (dp[v] == -1 || dp[u] + cost < dp[v]) {
                            dp[v] = dp[u] + cost;
                        }
                    }
                }
            }
            
            return dp[n - 1] != -1 && dp[n - 1] <= k;
        };
        
        int low = 0, high = edge_costs.size() - 1;
        int ans = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(edge_costs[mid])) {
                ans = edge_costs[mid];
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};