class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int max_cost = 0;
        for (int cost : costs) {
            if (cost > max_cost) {
                max_cost = cost;
            }
        }

        vector<int> count(max_cost + 1, 0);
        for (int cost : costs) {
            count[cost]++;
        }

        int ice_cream_count = 0;
        for (int i = 1; i <= max_cost; ++i) {
            if (count[i] == 0) {
                continue;
            }
            if (coins < i) {
                break;
            }
            
            long long total_cost = (long long)i * count[i];
            if (coins >= total_cost) {
                ice_cream_count += count[i];
                coins -= total_cost;
            } else {
                int buy = coins / i;
                ice_cream_count += buy;
                coins -= buy * i;
                break;
            }
        }

        return ice_cream_count;
    }
};