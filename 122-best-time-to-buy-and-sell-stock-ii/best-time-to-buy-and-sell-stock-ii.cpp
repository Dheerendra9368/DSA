class Solution {
public:
    int mxprofit(vector<int>& prices,int i,int prev,vector<vector<int>> &dp){
        int n=prices.size();
        if(i==n) return 0;
        if(dp[i][prev]!=-1) return dp[i][prev];

        //everyday u have three choice buy or sell or let it go
        int opt1=0,opt2=0,opt3=0;
        if(prev!=n) opt1=prices[i]-prices[prev]+mxprofit(prices,i+1,n,dp);//can sell stock
        if(prev==n) opt2=mxprofit(prices,i+1,i,dp);//buy the stock
        opt3=mxprofit(prices,i+1,prev,dp);//let it go as it was
        return dp[i][prev]=max(opt1,max(opt2,opt3));
    }
    int maxProfit(vector<int>& prices) {
        // int n=prices.size();
        // int prev=n;
        // vector<vector<int>> dp(n,vector<int>(n+1,-1));
        // return mxprofit(prices,0,n,dp);
        int n=prices.size();
        int ans=0;
        int i=0;
        while(i+1<n && prices[i+1]<prices[i]) i++;
        if(i==n) return ans;
        //now u can buy one
        int prev=prices[i];
        while(i<n){
            //now look till when it goes up
            while(i+1<n && prices[i+1]>prices[i]){
                i++;
            }
            ans+=prices[i]-prev;
            if(i+1==n) return ans;
            i++;
            prev=prices[i];
        }
        return ans;
    }
};