class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;

        // Step 1: Same value wale saare indices ko group karne ke liye map
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < n; i++) {
            graph[arr[i]].push_back(i);
        }

        // Step 2: BFS ke liye queue aur visited array
        queue<int> q;
        vector<bool> visited(n, false);

        q.push(0);
        visited[0] = true;
        int steps = 0;

        // Step 3: Standard BFS Loop
        while (!q.empty()) {
            int size = q.size();
            
            // Current level ke saare nodes ko process karein
            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();

                // Agar hum last index par pahunch gaye hain
                if (curr == n - 1) return steps;

                // Option 1: Jumps to same values (arr[i] == arr[j])
                for (int nextIdx : graph[arr[curr]]) {
                    if (!visited[nextIdx]) {
                        visited[nextIdx] = true;
                        q.push(nextIdx);
                    }
                }
                // IMPORTANT OPTIMIZATION: TLE se bachne ke liye map se clear karein
                graph[arr[curr]].clear();

                // Option 2: Forward step (i + 1)
                if (curr + 1 < n && !visited[curr + 1]) {
                    visited[curr + 1] = true;
                    q.push(curr + 1);
                }

                // Option 3: Backward step (i - 1)
                if (curr - 1 >= 0 && !visited[curr - 1]) {
                    visited[curr - 1] = true;
                    q.push(curr - 1);
                }
            }
            steps++; // Ek level complete hone par step count badhaein
        }

        return -1;
    }
};