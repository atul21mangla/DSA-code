class Solution {
public:
void dfs(int node , vector<vector<int>>& rooms , vector<int> &visited){
    visited[node]=true;

    for(auto u:rooms[node]){
        if(!visited[u])dfs(u,rooms,visited);
    }
}

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>visited(n,false);
        visited[0]=true;

        dfs(0,rooms,visited);
        for(int i=0;i<n;i++){
            if(!visited[i])return false;
        }
        return true;
    }
};