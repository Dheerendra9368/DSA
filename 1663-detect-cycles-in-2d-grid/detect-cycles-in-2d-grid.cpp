class Solution {
public:
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};

    bool dfs(int r,int c,vector<vector<char>>& grid,vector<vector<int>> & vis,int pr,int pc,char ch){
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int newr=r+dir[i][0];
            int newc=c+dir[i][1];
            if(newr<0 || newr>=grid.size() || newc<0 || newc>=grid[0].size()) continue;
            if(grid[newr][newc]!=ch) continue;
            if(vis[newr][newc] && (pr!=newr || pc!=newc)) return true;
            if(vis[newr][newc]==0){
                bool ans=dfs(newr,newc,grid,vis,r,c,ch);
                if(ans) return true;
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0){
                    bool ans=dfs(i,j,grid,vis,-1,-1,grid[i][j]);
                    if(ans) return true;
                }
            }
        }
        return false;
    }
};