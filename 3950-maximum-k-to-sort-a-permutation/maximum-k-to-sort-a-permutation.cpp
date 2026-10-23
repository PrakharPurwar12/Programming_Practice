class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans = 0;
        bool first = true;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i) {
                if(first){
                    ans = nums[i];
                    first = false;
                }else{
                    ans = ans & nums[i];
                }
            }
        }
        return ans;
    }
};