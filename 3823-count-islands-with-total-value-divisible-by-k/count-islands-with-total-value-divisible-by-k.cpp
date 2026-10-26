class Solution {
public:
    vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(vector<vector<int>>& grid,int r,int c,vector<vector<int>> &vis,long long &s){
        int n=grid.size();
        int m=grid[0].size();
        s+=grid[r][c];
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int newr=r+dir[i][0];
            int newc=c+dir[i][1];
            if(newr<0 || newc<0 || newr==n || newc==m || vis[newr][newc] || grid[newr][newc]==0) continue;
            dfs(grid,newr,newc,vis,s);
        }
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0 && !vis[i][j]){
                    long long s=0;
                    dfs(grid,i,j,vis,s);
                    if(s%k==0) cnt++;
                }
            }
        }
               return cnt;
    }
};