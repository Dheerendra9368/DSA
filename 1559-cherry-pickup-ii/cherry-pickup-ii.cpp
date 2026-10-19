class Solution {
public:
    int mxpickup(int i,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>> &dp){
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || j1<0 || j2<0 || i==n || j1==m || j2==m) return 0;
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int ans=0;
        for(int k1=-1;k1<=1;k1++){
            for(int k2=-1;k2<=1;k2++){
                ans=max(ans,mxpickup(i+1,j1+k1,j2+k2,grid,dp));
            }
        }
        if(j1==j2) return dp[i][j1][j2]=grid[i][j1]+ans;
        else return dp[i][j1][j2]=grid[i][j1]+grid[i][j2]+ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return mxpickup(0,0,m-1,grid,dp);
    }
};