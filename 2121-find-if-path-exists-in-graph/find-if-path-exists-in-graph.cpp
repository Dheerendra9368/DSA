class Solution {
public:
    bool exists(vector<vector<int>>& graph,int src,int dest,vector<int> &vis){
        if(src==dest) return true;
        vis[src]=1;
        for(auto ele:graph[src]){
            if(vis[ele]==1) continue;
            bool ans=exists(graph,ele,dest,vis);
            if(ans) return true;
        }
        // vis[src]=0;
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for(auto ele:edges){
            int src=ele[0];
            int dest=ele[1];
            graph[src].push_back(dest);
            graph[dest].push_back(src);
        }
        vector<int> vis(n,0);
        return exists(graph,source,destination,vis);
    }
};