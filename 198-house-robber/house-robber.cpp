class Solution {
public:
    int mxmoney(int i,vector<int>& nums,vector<int> &dp){
        if(i==0) return nums[0];
        if(i==1) return max(nums[0],nums[1]);
        if(dp[i]!=-1) return dp[i];

        int opt1=nums[i]+mxmoney(i-2,nums,dp);//max monet till index i = curridx money + money till 2nd prev idx
        int opt2=mxmoney(i-1,nums,dp);//continue with the money looted till prev idx
        return dp[i]=max(opt1,opt2);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return mxmoney(n-1,nums,dp);
    }
};