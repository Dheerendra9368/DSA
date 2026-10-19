class Solution {
public:
    int mnsum(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        int n=matrix.size();
        if(i<0 || i==n) return INT_MAX;
        int m=matrix[i].size();
        if(j<0 || j==m) return INT_MAX;
        if(i==n-1) return matrix[i][j];
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        int right=mnsum(i+1,j+1,matrix,dp);
        int below=mnsum(i+1,j,matrix,dp);
        return dp[i][j]=matrix[i][j]+min(right,below);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        return mnsum(0,0,triangle,dp);        
    }
};