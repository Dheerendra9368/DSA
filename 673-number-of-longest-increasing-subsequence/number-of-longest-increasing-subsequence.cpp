class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> len(n,1);
        int mx=1;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]>nums[j]){
                    if(dp[i]<1+dp[j]){
                        dp[i]=1+dp[j];
                        len[i]=len[j];
                    }
                    else if(dp[i]==1+dp[j]) len[i]+=len[j];
                }
            }
            //len[dp[i]]++;
            mx=max(mx,dp[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]==mx) ans+=len[i];
        }
        return ans;
    }
};