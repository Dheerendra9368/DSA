class Solution {
public:
    int totalcnt(int i,int j,string &s, string &t,vector<vector<int>> &dp){
        if(j<0) return 1;
        else if(i<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]!=t[j]) return dp[i][j]=totalcnt(i-1,j,s,t,dp);
        else{
            int pick=totalcnt(i-1,j-1,s,t,dp);
            int skip=totalcnt(i-1,j,s,t,dp);
            return dp[i][j]=skip+pick;
        }
    }

    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return totalcnt(n-1,m-1,s,t,dp);
    }
};