class Solution {
public:
    bool isSquare(int n){
        int root=(int)sqrt(n);
        return (n-root*root)==0;
    }

    int minSquare(int n,vector<int> &dp){
          if(isSquare(n)) return 1;
          if(dp[n]!=-1) return dp[n];
            int mini=n;
            for(int i=1;i*i<=n;i++){
           int count=minSquare(i*i,dp)+minSquare(n-i*i,dp);
           mini=min(mini,count);
    
        }
        return dp[n]=mini;
    }
    int numSquares(int n) {
       vector<int> dp(n+1);
       for(int i=1;i<=n;i++){
        if(isSquare(i)) dp[i]=1;
        else{
            int mini=n;
            for(int j=1;j*j<=i;j++){
                int count=dp[j*j]+dp[i-j*j];
                mini=min(count,mini);
            }
            dp[i]=mini;
        }
       }
       return dp[n];
    }
};