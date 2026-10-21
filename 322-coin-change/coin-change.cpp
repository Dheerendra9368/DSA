class Solution {
public:
    int mx(int i,int amn, vector<int> &coins,vector<vector<int>> &dp){
        if(amn==0) return 0;
        if(i==coins.size() || amn<0) return INT_MAX;
        if(dp[i][amn]!=-1) return dp[i][amn];
        int pick=0;
        int temp=mx(i,amn-coins[i],coins,dp);
        if(temp!=INT_MAX) pick+=1+temp;
        else pick=INT_MAX;
        int skip=mx(i+1,amn,coins,dp);
        return dp[i][amn]=min(pick,skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans=mx(0,amount,coins,dp);
        if(ans==INT_MAX) return -1;
        else return ans;
    }
};