class Solution {
public:
    int tmat(int i,int j,vector<vector<int>>& matrix,vector<vector<int>> &dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int upper=tmat(i-1,j,matrix,dp);
        int left=tmat(i,j-1,matrix,dp);
        int diag=tmat(i-1,j-1,matrix,dp);
        if(matrix[i][j]==1) return dp[i][j]=1+min(upper,min(left,diag));
        else return dp[i][j]=0;
    }
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        tmat(m-1,n-1,matrix,dp);
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++) ans+=dp[i][j];
        }
        return ans;       
    }
};