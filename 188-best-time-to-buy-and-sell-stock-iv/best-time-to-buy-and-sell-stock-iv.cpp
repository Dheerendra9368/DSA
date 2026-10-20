class Solution {
public:
        int mx(int i,int buy,int cnt,vector<int>& prices,vector<vector<vector<int>>> &dp){
        if(i>=prices.size() || cnt==0) return 0;
        if(dp[i][buy][cnt]!=-1) return dp[i][buy][cnt];
        if(buy){
            int Buy=-prices[i]+mx(i+1,0,cnt,prices,dp);
            int skip=mx(i+1,1,cnt,prices,dp);
            return dp[i][buy][cnt]=max(Buy,skip);
        }
        else{
            int skip=mx(i+1,0,cnt,prices,dp);
            int Sell=prices[i]+mx(i+1,1,cnt-1,prices,dp);
            return dp[i][buy][cnt]=max(Sell,skip);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));//size,can buy,cnt
        return mx(0,1,k,prices,dp);        
    }
};