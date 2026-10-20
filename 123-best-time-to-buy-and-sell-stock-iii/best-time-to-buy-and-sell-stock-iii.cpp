class Solution {
public:
        int mx(int i,int buy,int cnt,vector<int>& prices,vector<vector<vector<int>>> &dp){
        if(i>=prices.size() || cnt==2) return 0;
        if(dp[i][buy][cnt]!=-1) return dp[i][buy][cnt];
        if(buy){
            int Buy=-prices[i]+mx(i+1,0,cnt,prices,dp);
            int skip=mx(i+1,1,cnt,prices,dp);
            return dp[i][buy][cnt]=max(Buy,skip);
        }
        else{
            int skip=mx(i+1,0,cnt,prices,dp);
            int Sell=prices[i]+mx(i+1,1,cnt+1,prices,dp);
            return dp[i][buy][cnt]=max(Sell,skip);
        }
    }
    int maxProfit(vector<int>& prices) {
        // int n=prices.size();
        // vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(2,-1)));//size,can buy,cnt
        // return mx(0,1,0,prices,dp);
        int buy1 = INT_MIN, sell1 = 0;
        int buy2 = INT_MIN, sell2 = 0;

        for (int p : prices) {
            buy1  = max(buy1, -p);          // best balance after first buy
            sell1 = max(sell1, buy1 + p);   
            buy2  = max(buy2, sell1 - p);   
            sell2 = max(sell2, buy2 + p);   // best profit after second sell
        }
        return sell2;      
    }
};