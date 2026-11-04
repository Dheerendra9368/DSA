class Solution {
public:
    vector<vector<bool>> palin;
   

    int tp(int i,int j,string &s,vector<vector<int>> &dp){
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(palin[i][j]) return dp[i][j]=0;
        int mn=INT_MAX;
        for(int k=i;k<j;k++){
            if(palin[i][k]) mn=min(mn,tp(k+1,j,s,dp)+1);
        }
        return dp[i][j]=mn;
    }

    int minCut(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        palin.resize(n,vector<bool>(n));
        for(int j=0;j<n;j++){
            for(int i=0;i<=j;i++){
                if(s[i]==s[j] && (j-i<=2 || palin[i+1][j-1])) palin[i][j]=true;
            }
        }
        return tp(0,n-1,s,dp);
    }
};