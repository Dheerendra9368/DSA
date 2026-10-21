class Solution {
public:
    int mx(int i,int buy,vector<int>& prices, int &fee,vector<vector<int>> &dp){
        if(i==prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
            int a=-prices[i]+mx(i+1,0,prices,fee,dp);
            int b=mx(i+1,buy,prices,fee,dp);
            return dp[i][buy]=max(a,b);
        }
        else{
            int a=prices[i]-fee+mx(i+1,1,prices,fee,dp);
            int b=mx(i+1,buy,prices,fee,dp);
            return dp[i][buy]=max(a,b);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return mx(0,1,prices,fee,dp);
    }
};