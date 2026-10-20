class Solution {
public:
    int mxsr(int i,int j,vector<vector<char>>& matrix,vector<vector<int>> &dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int upper=mxsr(i-1,j,matrix,dp);
        int left=mxsr(i,j-1,matrix,dp);
        int diag=mxsr(i-1,j-1,matrix,dp);
        if(matrix[i][j]=='1') return dp[i][j]=1+min(upper,min(left,diag));
        else return dp[i][j]=0;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        mxsr(m-1,n-1,matrix,dp);
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++) ans=max(dp[i][j],ans);
        }
        return ans*ans;
    }
};