class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n = nums2.size();

        for(int i = 0; i < nums1.size(); i++) {
            int target = nums1[i];

            int idx = -1;
            for(int k = 0; k < n; k++) {
                if(nums2[k] == target) {
                    idx = k;
                    break;
                }
            }

            int element = -1;
            for(int j = idx + 1; j < n; j++) {
                if(nums2[j] > target) {
                    element = nums2[j];
                    break;   
                }
            }

            ans.push_back(element);
        }

        return ans;
    }
};