class Solution {
public:
    bool exist(int i,vector<int> &arr, int tar,vector<vector<int>> &dp){
        if(tar==0) return true;
        if(i<0 || tar<0) return false;
        if(dp[i][tar]!=-1) return dp[i][tar];
        int pick=exist(i-1,arr,tar-arr[i],dp);
        int skip=exist(i-1,arr,tar,dp);
        return dp[i][tar]=pick || skip;
    }

    bool canPartition(vector<int>& arr) {
        int n=arr.size();
        int target=0;
        for(int x:arr) target+=x;
        if(target%2!=0) return false;
        target/=2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return exist(n-1,arr,target,dp);        
    }
};