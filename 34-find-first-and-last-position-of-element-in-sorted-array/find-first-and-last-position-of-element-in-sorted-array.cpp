class Solution {
public:
    int firstOccur(vector<int>& nums, int key){
        int left = 0;
        int right = nums.size() - 1;
        int ans = -1;
        while(left<=right){
            int mid = left + (right - left) / 2;
            if(nums[mid]==key){
                ans = mid;
                right = mid - 1;
            }
            else if(nums[mid]>key){
                right = mid - 1;
            }else {
                left = mid + 1;
            }
        }
        return ans;
    }
    int lastOccur(vector<int>& nums, int key){
        int left = 0;
        int right = nums.size() - 1;
        int ans = -1;
        while(left<=right){
            int mid = left + (right - left) / 2;
            if(nums[mid]==key){
                ans = mid;
                left = mid + 1;
            }
            else if(nums[mid]>key){
                right = mid - 1;
            }else {
                left = mid + 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {

        int first = firstOccur(nums, target);
        int last = lastOccur(nums, target);

        return {first, last};
    }
};