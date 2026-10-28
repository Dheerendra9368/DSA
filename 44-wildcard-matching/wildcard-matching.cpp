class Solution {
public:

    bool mtc(int i,int j,string &s, string &p,vector<vector<int>> &dp){
        if(i<0 && j<0) return true;
        else if(i<0){
            for(int k=0;k<=j;k++){
                if(p[k]!='*') return false;
            }
            return true;
        }
        if(j<0) return false;
        
        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==p[j] || p[j]=='?') return dp[i][j]=mtc(i-1,j-1,s,p,dp);
        else if(p[j]=='*') return dp[i][j]=mtc(i-1,j-1,s,p,dp) || mtc(i-1,j,s,p,dp) || mtc(i,j-1,s,p,dp);
        else return dp[i][j]=false;
    }

    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return mtc(n-1,m-1,s,p,dp);
    }
};