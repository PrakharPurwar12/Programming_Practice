class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> component(n, 0);
        int compId = 0;
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i - 1] > maxDiff) {
                compId++;
            }
            component[i] = compId;
        }
        
        vector<bool> answer;
        answer.reserve(queries.size());
        
        for (const auto& q : queries) {
            answer.push_back(component[q[0]] == component[q[1]]);
        }
        
        return answer;
    }
};