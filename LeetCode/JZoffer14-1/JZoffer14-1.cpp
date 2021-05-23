class Solution {
public:
    int cuttingRope(int n) {
        switch(n) {
            case 2 : return 1; break;
            case 3 : return 2; break;
            case 4 : return 4; break;
            default : break;
        }

        switch(n % 3) {
            case 0 : return pow(3, n/3); break;
            case 1 : return pow(3, n/3 - 1) * 4; break;
            case 2 : return pow(3, n/3) * 2; break;
            default : break;
        }
        
        return 0;
    }
};
