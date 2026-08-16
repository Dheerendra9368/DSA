class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(int r,int c,vector<vector<int>>& grid,vector<vector<int>> &vis){
        if(vis[r][c]==1) return;
        int n=grid.size();
        int m=grid[0].size();
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int newr=r+dir[i][0];
            int newc=c+dir[i][1];
            if(newr<0 || newr>=n || newc<0 || newc>=m || grid[newr][newc]!=1){
                ans.push_back({r,c});
                continue;
            }
            if(vis[newr][newc]==0){
                dfs(newr,newc,grid,vis);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            int flag=0;
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    flag=1;
                    dfs(i,j,grid,vis);
                    break;
                }
            }
            if(flag==1) break;
        }
        queue<pair<int,int>> q;
        for(auto ele:ans){
            q.push({ele[0],ele[1]});
        }
        int dis=0;
        while(q.size()>0){
            int sz=q.size();
            while(sz--){
                auto ele=q.front();
                q.pop();
                int r=ele.first;
                int c=ele.second;
                 for(int i=0;i<4;i++){
                    int newr=r+dir[i][0];
                    int newc=c+dir[i][1];
                    if(newr<0 || newr>=n || newc<0 || newc>=n || vis[newr][newc]) continue;
                    if(grid[newr][newc]==1){
                        return dis;
                    }
                    q.push({newr,newc});
                    vis[newr][newc]=1;
                 }
            }
            dis++;
        }
        return dis;
    }
};