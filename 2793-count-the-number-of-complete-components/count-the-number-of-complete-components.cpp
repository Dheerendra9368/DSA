class Solution {
public:
    bool dfs(int x,vector<vector<int>> &graph,vector<bool> &vis,int &sz){
        if(graph[x].size()!=sz) return false;
        if(vis[x]==true) return true;
        vis[x]=true;
        for(int neighbor:graph[x]){
            if(vis[neighbor]==true) continue;
            bool ans=dfs(neighbor,graph,vis,sz);
            if(ans==false) return false;
        }
        return true;
    }

    void dfs2(int x,vector<vector<int>> &graph,vector<bool> &vis,int &sz){
        if(vis[x]==true) return;
        vis[x]=true;
        sz++;
        for(int neighbor:graph[x]){
            if(vis[neighbor]==true) continue;
            dfs2(neighbor,graph,vis,sz);
        }
        return;
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto edge:edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> vis(n,false);
        vector<bool> vis2(n,false);
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                int sz=0;
                dfs2(i,graph,vis2,sz);
                sz--;
                if(dfs(i,graph,vis,sz))   ans++;
            }
        }
        return ans;
    }
};