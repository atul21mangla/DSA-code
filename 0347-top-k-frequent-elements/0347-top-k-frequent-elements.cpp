class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int>mpp;
        for(int x:nums){
            mpp[x]++;
        }
        priority_queue<pair<int,int>>pq;
        for(pair p:mpp){
            pq.push({p.second,p.first});
        }
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};