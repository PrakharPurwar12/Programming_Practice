class Solution {
public:
    int minElement(vector<int>& nums) {
        int min_val = INT_MAX;
        for(int num:nums){
            int d_sum = 0;
            int temp = num;
            while(temp>0){
                d_sum+=temp%10;
                temp/=10;
            }
            min_val = min(min_val,d_sum);
        }
        return min_val;
        
        
    }
};