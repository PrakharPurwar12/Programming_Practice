#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
private:
    int getMinTime(const vector<int>& startA, const vector<int>& durationA, 
                   const vector<int>& startB, const vector<int>& durationB) {
        
        int n = startA.size();
        int m = startB.size();
        
        vector<pair<int, int>> ridesB(m);
        for (int i = 0; i < m; ++i) {
            ridesB[i] = {startB[i], durationB[i]};
        }
        sort(ridesB.begin(), ridesB.end());
        
        vector<int> prefMinDuration(m);
        prefMinDuration[0] = ridesB[0].second;
        for (int i = 1; i < m; ++i) {
            prefMinDuration[i] = min(prefMinDuration[i - 1], ridesB[i].second);
        }
        
        vector<int> suffMinFinish(m);
        suffMinFinish[m - 1] = ridesB[m - 1].first + ridesB[m - 1].second;
        for (int i = m - 2; i >= 0; --i) {
            suffMinFinish[i] = min(suffMinFinish[i + 1], ridesB[i].first + ridesB[i].second);
        }
        
        int minTotalFinishTime = INT_MAX;
        
        for (int i = 0; i < n; ++i) {
            int finishA = startA[i] + durationA[i];
            
            auto it = upper_bound(ridesB.begin(), ridesB.end(), make_pair(finishA, INT_MAX));
            int idx = distance(ridesB.begin(), it);
            
            if (idx > 0) {
                int currentFinish = finishA + prefMinDuration[idx - 1];
                minTotalFinishTime = min(minTotalFinishTime, currentFinish);
            }
            
            if (idx < m) {
                int currentFinish = suffMinFinish[idx];
                minTotalFinishTime = min(minTotalFinishTime, currentFinish);
            }
        }
        
        return minTotalFinishTime;
    }

public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, 
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int option1 = getMinTime(landStartTime, landDuration, waterStartTime, waterDuration);
        
        int option2 = getMinTime(waterStartTime, waterDuration, landStartTime, landDuration);
        
        return min(option1, option2);
    }
};