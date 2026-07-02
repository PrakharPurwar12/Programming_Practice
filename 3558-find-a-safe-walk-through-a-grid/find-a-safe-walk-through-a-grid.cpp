class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> max_health(m, vector<int>(n, -1));
        deque<pair<int, int>> dq;
        
        int start_health = health - grid[0][0];
        if (start_health <= 0) return false;
        
        max_health[0][0] = start_health;
        dq.push_front({0, 0});
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();
            
            if (r == m - 1 && c == n - 1) {
                return max_health[r][c] >= 1;
            }
            
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int next_health = max_health[r][c] - grid[nr][nc];
                    
                    if (next_health > max_health[nr][nc]) {
                        max_health[nr][nc] = next_health;
                        if (grid[nr][nc] == 0) {
                            dq.push_front({nr, nc});
                        } else {
                            dq.push_back({nr, nc});
                        }
                    }
                }
            }
        }
        
        return max_health[m - 1][n - 1] >= 1;
    }
};