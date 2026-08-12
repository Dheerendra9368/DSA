class Solution {
public:
void exists(vector<vector<int>>& graph,int src,int dest,vector<int> &vis,vector<int> temp,vector<vector<int>> &ans){
        if(src==dest){
            temp.push_back(src);
            ans.push_back(temp);
            return;
        }
        vis[src]=1;
        temp.push_back(src);
        for(auto ele:graph[src]){
            if(vis[ele]==1) continue;
            exists(graph,ele,dest,vis,temp,ans);
        }
        vis[src]=0;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        int n=graph.size();
        vector<int> vis(n,0);
        exists(graph,0,n-1,vis,{},ans);
        return ans;
    }
};