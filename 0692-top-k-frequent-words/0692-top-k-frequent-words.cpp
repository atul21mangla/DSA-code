class myComparator{
    public:
    bool operator()(const pair<string,int>p1 , pair<string,int>p2){
        if(p1.second==p2.second)return p1.first < p2.first;
        return p1.second > p2.second;
    }
};



class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mpp;
        int n = words.size();

        for(int i=0;i<n;i++){
            mpp[words[i]]++;
        }

        priority_queue<pair<string,int>, vector<pair<string,int>> , myComparator>pq;

        for(const auto& x:mpp){
            pq.push({x.first,x.second});

            if(pq.size()>k){
                pq.pop();
            }
        }

        vector<string>ans(k);
        int m = k-1;

        while(pq.size()>0){
            ans[m--] = pq.top().first;
            pq.pop();
        }
        return ans;
    }
};