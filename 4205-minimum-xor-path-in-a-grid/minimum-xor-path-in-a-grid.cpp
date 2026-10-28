class Solution {
public:
    int mncost(int r,int c,int x,vector<vector<int>>& grid,vector<vector<vector<int>>> &dp){
        int n=grid.size();
        int m=grid[0].size();        
        if(r==n || c==m) return 1024;
        if(r==n-1 && c==m-1) return x^grid[r][c];
        if(dp[r][c][x]!=INT_MAX) return dp[r][c][x];
        int down=mncost(r+1,c,grid[r][c]^x,grid,dp);
        int right=mncost(r,c+1,grid[r][c]^x,grid,dp);
        return dp[r][c][x]=min(down,right);
    }
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(2048,INT_MAX)));
        return mncost(0,0,0,grid,dp);
    }
};