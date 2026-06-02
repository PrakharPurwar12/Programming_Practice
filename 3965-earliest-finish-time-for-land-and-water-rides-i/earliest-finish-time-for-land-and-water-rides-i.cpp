class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int minFinishTime = INT_MAX;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                
                int landEndTime = landStartTime[i] + landDuration[i];
                int totalTime1 = max(landEndTime, waterStartTime[j]) + waterDuration[j];
                
                int waterEndTime = waterStartTime[j] + waterDuration[j];
                int totalTime2 = max(waterEndTime, landStartTime[i]) + landDuration[i];
                
                minFinishTime = min({minFinishTime, totalTime1, totalTime2});
            }
        }

        return minFinishTime;
    }
};
        