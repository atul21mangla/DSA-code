class Solution {

private:
    void topo(int numCourses , vector<int>g[] , vector<int>& inDeg , vector<int>& res){
        queue<int>q;

        for(int i=0;i<numCourses;i++){
            if(inDeg[i]==0)q.push(i);
        }

        while(!q.empty()){
            int node = q.front();q.pop();
            res.push_back(node);

            for(auto u:g[node]){
                inDeg[u]--;
                if(inDeg[u]==0)q.push(u);
            }
        }
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // we need to print topological order

        // using Kahn's Algorithm

        int edges = prerequisites.size();
        vector<int> g[numCourses];
        for(auto x:prerequisites){
            g[x[1]].push_back(x[0]);
        }

        vector<int>inDeg(numCourses,0);

        for(int i=0;i<numCourses;i++){
            for(int u:g[i]){
                inDeg[u]++;
            }
        }

        vector<int>res;
        topo(numCourses,g,inDeg,res);
        if(res.size()==numCourses)return res;
        else return {};
    }
};