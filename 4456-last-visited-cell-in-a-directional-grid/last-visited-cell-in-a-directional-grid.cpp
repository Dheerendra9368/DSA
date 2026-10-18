class Solution {
public:
    vector<int> dfs(vector<vector<int>> &vis,int r,int c,vector<vector<char>>& grid){
        int orgr=r;
        int orgc=c;
        vis[r][c]=1;
        if(grid[r][c]=='L') c--;
        else if(grid[r][c]=='R') c++; 
        else if(grid[r][c]=='D') r++;
        else r--;
        if(r==vis.size() || c==vis[0].size() || r<0 || c<0 || vis[r][c]==1){
            return {orgr,orgc};
        }
        else return dfs(vis,r,c,grid);
    }
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int r=0,c=0;
        return dfs(vis,r,c,grid);
    }
};