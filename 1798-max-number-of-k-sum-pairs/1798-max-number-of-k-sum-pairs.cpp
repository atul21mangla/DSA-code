class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_set<int>st;
        int count=0;

        unordered_map<int,int>mpp;
        for(auto x:nums)mpp[x]++;

        for(int i=0;i<n;i++){
            int x = nums[i];
            int cp = k-x;
            if(st.find(x)==st.end() && st.find(cp)==st.end()){
                if(x==cp){
                    count += mpp[x]/2;
                }
                else count += min(mpp[x] , mpp[cp]);

                st.insert(x);
                st.insert(cp);
            }
        }
        return count;
    }
};