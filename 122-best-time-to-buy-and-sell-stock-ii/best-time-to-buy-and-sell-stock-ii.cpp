class Solution {
public:
    int mx(int i,int buy,vector<int>& prices,vector<vector<int>> &dp){
        if(i>=prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
            int Buy=-prices[i]+mx(i+1,0,prices,dp);
            int skip=mx(i+1,1,prices,dp);
            return dp[i][buy]=max(Buy,skip);
        }
        else{
            int skip=mx(i+1,0,prices,dp);
            int Sell=prices[i]+mx(i+1,1,prices,dp);
            return dp[i][buy]=max(Sell,skip);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(2,vector<int>(2,0));
        dp[1][0]=dp[1][1]=0;
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
            if(buy){
            int Buy=-prices[i]+dp[1][0];
            int skip=dp[1][1];
            dp[0][buy]=max(Buy,skip);
        }
        else{
            int skip=dp[1][0];
            int Sell=prices[i]+dp[1][1];
            dp[0][buy]=max(Sell,skip);
        }
        } 
        dp[1]=dp[0];
            }
        return dp[0][1];
       // return mx(0,1,prices,dp);
    }
};