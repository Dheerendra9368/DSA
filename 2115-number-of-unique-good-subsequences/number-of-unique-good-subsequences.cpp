class Solution {
public:
    int MOD=1e9+7;
    int f(string &s,int n,vector<int> &dp,vector<int> &prev){
        if(n==0) return 1;
        if(dp[n]!=-1) return dp[n];
        if(s[n-1]=='0'){
            long long total=f(s,n-1,dp,prev);
            if(prev[n]!=0){
                long long dup=f(s,prev[n]-1,dp,prev);
                total=(total+dup)%MOD;
            }
            return dp[n]=total;
        }
        else{
            int total=2*(f(s,n-1,dp,prev))%MOD;
            if(prev[n]!=0){
                int dup=f(s,prev[n]-1,dp,prev);
                total=(total-dup+MOD)%MOD;
            }
            return dp[n]=total%MOD;
        }
    }
    int numberOfUniqueGoodSubsequences(string s) {
        int n=s.size();
        vector<int> prev(n+1,0);
        int lastSeen=-1;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                cnt=1;
                if(lastSeen!=-1) prev[i+1]=lastSeen;
            }
            else{
                if(lastSeen!=-1) prev[i+1]=lastSeen;
                lastSeen=i+1;
            }
        }
        vector<int> dp(n+1,-1);
        return (f(s,n,dp,prev)-1+cnt+MOD)%MOD;
    }
};