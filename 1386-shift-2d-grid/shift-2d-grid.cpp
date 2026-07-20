class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        k = k % total;
        vector<vector<int>> result(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int old_1d = i * n + j;
                int new_1d = (old_1d + k) % total;
                int new_r = new_1d / n;
                int new_c = new_1d % n;
                result[new_r][new_c] = grid[i][j];
            }
        }
        return result;
    }
};