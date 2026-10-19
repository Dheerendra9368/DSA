class Solution {
public:
    int mnsum(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        int n=matrix.size();
        if(i<0 || j<0 || i==n || j==n) return INT_MAX;
        if(i==0) return matrix[i][j];
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        int left=mnsum(i-1,j-1,matrix,dp);
        int right=mnsum(i-1,j+1,matrix,dp);
        int above=mnsum(i-1,j,matrix,dp);
        return dp[i][j]=matrix[i][j]+min(above,min(left,right));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        int ans=INT_MAX;
        for(int i=0;i<n;i++) ans=min(ans,mnsum(n-1,i,matrix,dp));
        return ans;
    }
};