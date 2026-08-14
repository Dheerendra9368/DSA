class Solution {
public:
    vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(int r,int c,vector<vector<int>>& grid,vector<vector<int>> &vis){
        int n=grid.size();
        int m=grid[0].size();
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int newr=r+dir[i][0];
            int newc=c+dir[i][1];
            if(newr<0 || newr>=n || newc<0 || newc>=m || grid[r][c]>grid[newr][newc]){
                continue;
            }
            if(vis[newr][newc]==0){
                dfs(newr,newc,grid,vis);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visPacific(n,vector<int>(m,0));
        vector<vector<int>> visAtlantic(n,vector<int>(m,0));
        vector<vector<int>> Pacific;
        vector<vector<int>> Atlantic;
        for(int j=0;j<m;j++){
            Pacific.push_back({0,j});
            Atlantic.push_back({n-1,j});
        }
        for(int i=1;i<n;i++) Pacific.push_back({i,0});
        for(int i=0;i<n-1;i++) Atlantic.push_back({i,m-1});
        for(auto ele:Pacific){
            int r=ele[0];
            int c=ele[1];
            if(visPacific[r][c]==0) dfs(r,c,grid,visPacific);
        }
        for(auto ele:Atlantic){
            int r=ele[0];
            int c=ele[1];
            if(visAtlantic[r][c]==0) dfs(r,c,grid,visAtlantic);
        }

        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visPacific[i][j] == 1 && visAtlantic[i][j] == 1) ans.push_back({i,j});
            }
        }
        return ans;
    }
};