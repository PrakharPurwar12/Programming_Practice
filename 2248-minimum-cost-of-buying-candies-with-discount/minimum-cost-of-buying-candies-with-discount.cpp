class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());
        int totalcost = 0;
        int  n  = cost.size();

        for(int i=0; i<n; i++){
            if((i+1) % 3 == 0) continue;

            totalcost += cost[i];

        }
        return totalcost;

    }
};