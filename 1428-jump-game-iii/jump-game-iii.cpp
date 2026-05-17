class Solution {
private:
    bool solveDFS(vector<int>& arr, int curr, vector<bool>& visited) {
        // Base Case 1: Out of bounds check
        if (curr < 0 || curr >= arr.size()) {
            return false;
        }
        
        // Base Case 2: Already visited node (cycle detection)
        if (visited[curr]) {
            return false;
        }
        
        // Base Case 3: Target found
        if (arr[curr] == 0) {
            return true;
        }
        
        visited[curr] = true;
        
        bool walkRight = solveDFS(arr, curr + arr[curr], visited);
        bool walkLeft  = solveDFS(arr, curr - arr[curr], visited);
        
        return walkRight || walkLeft;
    }

public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);
        
        return solveDFS(arr, start, visited);
    }
};