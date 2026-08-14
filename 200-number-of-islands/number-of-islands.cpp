class Solution {
public:
    vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(int r,int c,vector<vector<char>>& grid,vector<vector<int>> &vis){
        int n=grid.size();
        int m=grid[0].size();
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int newr=r+dir[i][0];
            int newc=c+dir[i][1];
            if(newr<0 || newr>=n || newc<0 || newc>=m || grid[newr][newc]=='0'){
                continue;
            }
            if(vis[newr][newc]==0){
                dfs(newr,newc,grid,vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    dfs(i,j,grid,vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};