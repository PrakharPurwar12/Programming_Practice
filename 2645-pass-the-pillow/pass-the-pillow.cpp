class Solution {
public:
    int passThePillow(int n, int time) {
        int rounds = time / (n - 1);
        int rem = time % (n - 1);

        if(rounds % 2 == 0){
            return 1 + rem;
        }
        else{
            return n - rem;
        }
    }
};