class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = INT_MAX;
        bool even = false, odd = false;

        for(int x:nums1){
            mn = min(mn, x);

            if(x%2==0) even = true;

            else odd = true; 
        }
        if(!odd || !even) return true;

        return mn%2==1;
    }
};