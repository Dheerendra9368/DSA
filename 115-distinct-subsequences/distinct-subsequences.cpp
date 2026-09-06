class Solution {
public:
    int ts(string s1, string s2,int i,int j,vector<vector<int>> &dp){
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            int take=ts(s1,s2,i-1,j-1,dp);//if i wanna take this g(ex 2)
            int skip=ts(s1,s2,i-1,j,dp);//i wanna take previous g(ex2)
            return dp[i][j]=take+skip;
        }
        else return dp[i][j]=ts(s1,s2,i-1,j,dp);//no option
    }
    int numDistinct(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        vector<vector<double>> dp(m+1,vector<double>(n+1,0));
        for(int i=0;i<=m;i++)
            dp[i][0]=1;

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    double take=dp[i-1][j-1];//if i wanna take this g(ex 2)
                    double skip=dp[i-1][j];//i wanna take previous g(ex2)
                    dp[i][j]=take+skip;
            }
            else dp[i][j]=dp[i-1][j];//no option
            }
        }
        return (int)dp[m][n];
    }
};