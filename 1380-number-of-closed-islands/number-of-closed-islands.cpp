class Solution {
public:
    vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};

    void dfs(vector<vector<int>>& grid,int r,int c,vector<vector<int>> &vis){
        int n=grid.size();
        int m=grid[0].size();
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int newr=r+dir[i][0];
            int newc=c+dir[i][1];
            if(newr<0 || newc<0 || newr==n || newc==m || vis[newr][newc] || grid[newr][newc]==1) continue;
            dfs(grid,newr,newc,vis);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){// oth cloumn 0 check
            if(grid[i][0]==0 && !vis[i][0]) dfs(grid,i,0,vis);
        }
        for(int j=0;j<m;j++){ // oth row 0 check
            if(grid[0][j]==0 && !vis[0][j]) dfs(grid,0,j,vis);
        }

        for(int i=0;i<n;i++){ // m-1th clomun 0 check
            if(grid[i][m-1]==0 && !vis[i][m-1]) dfs(grid,i,m-1,vis);
        }

        for(int j=0;j<m;j++){ // n-1th row 0 check
            if(grid[n-1][j]==0 && !vis[n-1][j]) dfs(grid,n-1,j,vis);
        }

        int cnt=0;

        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(grid[i][j]==0 && !vis[i][j]){
                    dfs(grid,i,j,vis);
                    cnt++;
                }
            }
        }

        return cnt;

    }
};