class Solution {
public:
    int MOD=1e9+7;
    //side==0 means i have come from left side
    //side==1 means i have come from upper side
    int tpath(int r,int c,vector<vector<int>>& grid,int side,vector<vector<vector<int>>> &dp){
        int n=grid.size();
        int m=grid[0].size();
        if(r<0 || c<0 || r==n || c==m) return 0;
        if(r==n-1 && c==m-1) return 1;
        if(dp[r][c][side]!=-1) return dp[r][c][side];
        if(grid[r][c]==1 && side==0) return dp[r][c][side]=tpath(r+1,c,grid,1,dp)%MOD;
        else if(grid[r][c]==1 && side==1) return dp[r][c][side]=tpath(r,c+1,grid,0,dp)%MOD;
        else{
            return dp[r][c][side]=(tpath(r+1,c,grid,1,dp)%MOD+tpath(r,c+1,grid,0,dp)%MOD)%MOD;
        }
    }

    int uniquePaths(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (m,vector<int>(2,-1)));
        return tpath(0,0,grid,0,dp);//grid[0][0]==0 so no matter what side we send 0 or 1
    }
};