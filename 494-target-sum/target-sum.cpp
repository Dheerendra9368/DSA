class Solution {
public:
    int mx(int i,int tar,vector<int>& nums,vector<vector<int>> &dp,int &s){
        if (tar < -s || tar > s) return 0;
        if(tar==0 && i<0) return 1;
        if(i<0) return 0;
        if(dp[i][tar+s]!=-1) return dp[i][tar+s];
        int add=mx(i-1,tar-nums[i],nums,dp,s);
        int sub=mx(i-1,tar+nums[i],nums,dp,s);
        return dp[i][tar+s]=add+sub;
    }

    int findTargetSumWays(vector<int>& nums,int target) {
        int n=nums.size();
        int s=0;
        for(int x:nums) s+=x;
        if(target>s || target<-s) return 0;
        vector<vector<int>> dp(n,vector<int>(2*s+1,-1));
        return mx(n-1,target,nums,dp,s);
    }
};