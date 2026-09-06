class Solution {
public:
    vector<vector<int>> dir={{-1,0},{1,0},{0,1},{0,-1}};
    int f(vector<vector<int>>& grid, int k,vector<vector<vector<vector<int>>>> &dp,int r,int c,int idx){
        if(k<0) return INT_MAX;
        int n=grid.size();
        int m=grid[0].size();
        if(r==n-1 && c==m-1) return grid[r][c];
       if(dp[idx][k][r][c]!=-1) return dp[idx][k][r][c];
        int a=INT_MAX;
        for(int i=0;i<4;i++){
            int newr=r+dir[i][0];
            int newc=c+dir[i][1];
            if(newr<0 || newr>=n || newc<0 || newc>=m) continue;
            if(i==idx || idx==4) a=min(a,f(grid,k,dp,newr,newc,i));
            else a=min(a,f(grid,k-1,dp,newr,newc,i));
        }
        if(a==INT_MAX) return dp[idx][k][r][c]=INT_MAX;
        return dp[idx][k][r][c]=grid[r][c]+a;
        
    }
    int minCost(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<vector<int>>>> dp(5,vector<vector<vector<int>>>(k+1,vector<vector<int>>(n,vector<int>(m,-1))));
        int res= f(grid,k,dp,0,0,4);
        if(res==INT_MAX) return -1;
        return res;
    }
};