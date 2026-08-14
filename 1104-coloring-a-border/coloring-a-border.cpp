class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(int r,int c,vector<vector<int>>& grid,vector<vector<int>> &vis,int color){
        if(vis[r][c]==1) return;
        int n=grid.size();
        int m=grid[0].size();
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int newr=r+dir[i][0];
            int newc=c+dir[i][1];
            if(newr<0 || newr>=n || newc<0 || newc>=m || grid[newr][newc]!=color){
                ans.push_back({r,c});
                continue;
            }
            if(vis[newr][newc]==0){
                dfs(newr,newc,grid,vis,color);
            }
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        dfs(row,col,grid,vis,grid[row][col]);
        for(auto ele:ans){
            int r=ele[0];
            int c=ele[1];
            grid[r][c]=color;
        }
        return grid;
    }
};