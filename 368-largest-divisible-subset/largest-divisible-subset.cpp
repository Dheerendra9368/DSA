class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1);
        vector<int> hash(n,0);
        dp[0]=1;
        int mx=dp[0];
        int ansidx=0;
        for(int i=1;i<n;i++){
            hash[i]=i;
            for(int j=i-1;j>=0;j--){
                if((nums[i]%nums[j]==0) && (1+dp[j]>dp[i])){
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }
            if(mx<dp[i]){
                mx=dp[i];
                ansidx=i;
            }
        }
        vector<int> res;
        res.push_back(nums[ansidx]);
        while(ansidx!=hash[ansidx]){
            ansidx=hash[ansidx];
            res.push_back(nums[ansidx]);
        }
        return res;
    }
};