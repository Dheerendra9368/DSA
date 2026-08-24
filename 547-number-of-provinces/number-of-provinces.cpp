class Solution {
public:
    void dfs(vector<vector<int>> &graph,int x,vector<int> &vis){
        vis[x]=1;
        for(int neighbor:graph[x]){
            if(vis[neighbor]) continue;
            vis[neighbor]=1;
            dfs(graph,neighbor,vis);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n,0);
        vector<vector<int>> graph(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j]==0) continue;
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                ans++;
                dfs(graph,i,vis);
            }
        }
        return ans;
    }
};