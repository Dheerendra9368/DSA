class Solution {
public:

    int mxget(int i,int j,vector<int>& nums,vector<vector<int>> &dp){
        int n=nums.size();
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mx=INT_MIN;
        for(int k=i;k<=j;k++){
            // i am the last one to burst means my left and my right have used meeeeeeeeeee
            int left=i==0 ? 1:nums[i-1];
            int right=j==n-1 ? 1:nums[j+1];
            int currval=left*nums[k]*right;
            int total=mxget(i,k-1,nums,dp)+mxget(k+1,j,nums,dp)+currval;
            mx=max(mx,total);
        }
        return dp[i][j]=mx;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return mxget(0,n-1,nums,dp);
    }
};