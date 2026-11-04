class Solution {
public:
    int part(int i,int j,vector<int>& arr, int &k,vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mx=arr[i];
        int mxsub=0;
        for(int p=i;p<=i+k-1 && p<=j;p++){
            mx=max(arr[p],mx);
            int len=p-i+1;
            mxsub=max(mxsub,len*mx+part(p+1,j,arr,k,dp));
        }
       return dp[i][j]=mxsub;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return part(0,n-1,arr,k,dp);
    }
};