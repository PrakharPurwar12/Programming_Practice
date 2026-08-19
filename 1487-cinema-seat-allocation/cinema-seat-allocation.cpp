class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rowMask;
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            if (col >= 2 && col <= 9) {
                rowMask[row] |= (1 << (col - 1));
            }
        }

        int total = (n - rowMask.size()) * 2;

        int leftMask = (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4);
        int rightMask = (1 << 5) | (1 << 6) | (1 << 7) | (1 << 8);
        int midMask = (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6);

        for (const auto& [row, mask] : rowMask) {
            bool left = (mask & leftMask) == 0;
            bool right = (mask & rightMask) == 0;
            bool mid = (mask & midMask) == 0;

            if (left && right) {
                total += 2;
            } else if (left || right || mid) {
                total += 1;
            }
        }

        return total;
    }
};