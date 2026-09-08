class Solution {
public:
    int MOD=1e9+7;
    int f(int n,vector<int> &dp,vector<int> &prev){
        if(n==0) return 1;
        if(dp[n]!=-1) return dp[n];
        int total=2*(f(n-1,dp,prev))%MOD;
        if(prev[n]!=0){
            int dup=f(prev[n]-1,dp,prev);
            total=(total-dup+MOD)%MOD;
        }
        return dp[n]=total%MOD;
    }

    int distinctSubseqII(string s) {
        int n=s.size();
        vector<int> prev(n+1,0);
        vector<int> lastSeen(26,-1);
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            if(lastSeen[idx]!=-1) prev[i+1]=lastSeen[idx];
            lastSeen[idx]=i+1;
        }
        vector<int> dp(n+1,-1);
        return (f(n,dp,prev)-1+MOD)%MOD;
    }
};