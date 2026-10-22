class Solution {
public:
    int mx(int i,int last,vector<int>& nums,vector<vector<int>> &dp){
        if(i==nums.size()) return 0;
        int pick=0;
        if(dp[i][last]!=-1) return dp[i][last];
        if(last==nums.size() || nums[last]<nums[i]) pick+=1+mx(i+1,i,nums,dp);
        int skip=mx(i+1,last,nums,dp);
        return dp[i][last]=max(pick,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return mx(0,n,nums,dp);
    }
};