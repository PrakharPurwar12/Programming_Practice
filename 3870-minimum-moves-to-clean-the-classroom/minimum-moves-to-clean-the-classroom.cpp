class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        
        int sr = -1, sc = -1;
        int litter_id[20][20];
        memset(litter_id, -1, sizeof(litter_id));
        
        int k = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                } else if (classroom[i][j] == 'L') {
                    litter_id[i][j] = k++;
                }
            }
        }
        
        int target_mask = (1 << k) - 1;
        if (target_mask == 0) return 0;
        
        int best_energy[20][20][1024];
        memset(best_energy, -1, sizeof(best_energy));
        
        struct State {
            int r, c, mask, e;
        };
        
        queue<State> q;
        q.push({sr, sc, 0, energy});
        best_energy[sr][sc][0] = energy;
        
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        int steps = 0;
        
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [r, c, mask, e] = q.front();
                q.pop();
                
                if (mask == target_mask) {
                    return steps;
                }
                
                if (e == 0) continue;
                
                for (int d = 0; d < 4; ++d) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    if (classroom[nr][nc] == 'X') continue;
                    
                    int ne = e - 1;
                    int nmask = mask;
                    
                    if (classroom[nr][nc] == 'L') {
                        nmask |= (1 << litter_id[nr][nc]);
                    }
                    if (classroom[nr][nc] == 'R') {
                        ne = energy;
                    }
                    
                    if (ne > best_energy[nr][nc][nmask]) {
                        best_energy[nr][nc][nmask] = ne;
                        q.push({nr, nc, nmask, ne});
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};