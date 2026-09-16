class Solution {
public:
    int MOD=1e9+7;
    int f(int &n,int k,int i,vector<vector<int>> &dp){
        if(k==0) return 1;
        if(i>=n) return 0;
        if(dp[k][i]!=-1) return dp[k][i];
        int skip=f(n,k,i+1,dp);
        int take=0;
        for(int j=i+1;j<n;j++){
            take=(take%MOD+f(n,k-1,j,dp)%MOD)%MOD;
        }
        return dp[k][i]=(skip%MOD+take%MOD)%MOD;
    }
    int numberOfSets(int n, int K) {
        vector<vector<int>> dp(K+1,vector<int>(n+1,0));
        for(int i=0;i<n;i++) dp[0][i]=1;
        for(int k=1;k<=K;k++){
            vector<int> prevsum(n+1,0);
            for(int i=n-1;i>=0;i--) prevsum[i]=(dp[k-1][i]%MOD+prevsum[i+1]%MOD)%MOD;
            for(int i=n-1;i>=0;i--){
                int skip=dp[k][i+1];
                int take=prevsum[i+1];
                dp[k][i]=(skip%MOD+take%MOD)%MOD;
            }
        }
        return dp[K][0];
    }
};