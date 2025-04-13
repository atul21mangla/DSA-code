class Solution {
public:
    int findClosest(int x, int y, int z) {
        int f = abs(z-x);
        int s = abs(z-y);
        if(f>s){
            return 2;
        }
        else if(f<s){
            return 1;
        }
        else
        return 0;
    }
};