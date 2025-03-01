#define ll long long int
class Solution {
public:
    int arrangeCoins(int n) {
        ll s = 1;
        ll e = n;
        ll ans = 0;
        while(s<=e){
            ll mid = s + (e-s)/2;
            if((mid*(mid+1)/2) > n){
                e = mid-1;
            }
            else{
                ans = mid;
                s = mid+1;
            }
        }
        return ans;
    }
};
                                                                        