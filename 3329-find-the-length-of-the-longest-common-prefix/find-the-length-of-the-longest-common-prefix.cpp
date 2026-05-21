class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;
        
        // Step 1: arr1 ke saare possible prefixes ko HashSet me insert karo
        for (int val : arr1) {
            while (val > 0) {
                prefixes.insert(val);
                val /= 10;
            }
        }
        
        int longest_prefix = 0;
        
        // Step 2: arr2 ke elements ke prefixes check karo
        for (int val : arr2) {
            while (val > 0) {
                // Agar prefix HashSet me mil jata hai
                if (prefixes.count(val)) {
                    // Number of digits calculate karo us prefix ki
                    int current_length = to_string(val).length();
                    longest_prefix = max(longest_prefix, current_length);
                    break; 
                }
                val /= 10;
            }
        }
        
        return longest_prefix;
    }
};