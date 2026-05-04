class Solution {
  public:
    bool isBinaryPalindrome(int n) {
        // code here
        string binary = "";
        
        while(n>0){
            if(n%2==0){
                binary+='0';
            }
            else{
                binary+='1';
            }
            n /=2;
        }
        int start = 0;
        int end = binary.length() - 1;
        
        while(start < end){
            if(binary[start] != binary[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
        
    }
};