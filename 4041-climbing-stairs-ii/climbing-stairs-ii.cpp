class Solution {
public:
    int mncost(int i,vector<int> &dp,vector<int>& costs){
        int n=costs.size();
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int opt1=INT_MAX,opt2=INT_MAX,opt3=INT_MAX;
        if(i+1<=n) opt1=costs[i+1-1]+1+mncost(i+1,dp,costs);
        if(i+2<=n) opt2=costs[i+2-1]+4+mncost(i+2,dp,costs);
        if(i+3<=n) opt3=costs[i+3-1]+9+mncost(i+3,dp,costs);
        return dp[i]=min(opt1,min(opt2,opt3));
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1,-1);
        return mncost(0,dp,costs);
    }
};