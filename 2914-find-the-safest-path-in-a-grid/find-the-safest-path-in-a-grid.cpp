class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return 0;

        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        queue<pair<int, int>> q;

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    dist[r][c] = 0;
                    q.push({r, c});
                }
            }
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == 1e9) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<int>> max_safeness(n, vector<int>(n, -1));

        pq.push({dist[0][0], {0, 0}});
        max_safeness[0][0] = dist[0][0];

        while (!pq.empty()) {
            auto [d, cell] = pq.top();
            pq.pop();
            int r = cell.first;
            int c = cell.second;

            if (r == n - 1 && c == n - 1) return d;

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    int s = min(d, dist[nr][nc]);
                    if (s > max_safeness[nr][nc]) {
                        max_safeness[nr][nc] = s;
                        pq.push({s, {nr, nc}});
                    }
                }
            }
        }

        return 0;
    }
};