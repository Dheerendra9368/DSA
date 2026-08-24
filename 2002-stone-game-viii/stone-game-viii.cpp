class Solution {
public:
    int f(vector<int> &pre,int i,vector<int> &dp){
        if(i==pre.size()-1) return pre[i];
        if(dp[i]!=-1) return dp[i];
        int temp=f(pre,i+1,dp);
        int take=pre[i]-temp;
        int skip=temp;
        return dp[i]=max(take,skip);
    }
    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        if(n==2) return stones[0]+stones[1];
        vector<int> pre(n);
        pre[0]=stones[0];
        for(int i=1;i<n;i++) pre[i]=pre[i-1]+stones[i];
        vector<int> dp(n,-1);
       return f(pre,1,dp);
    
    }
};