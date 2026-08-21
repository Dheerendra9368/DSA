class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n));
        int mx=0;
        string ans="";
        for(int k=0;k<n;k++){
            int i=0,j=k;
            while(j<n){
                if(i==j){
                    dp[i][j]=1;
                    mx=1;
                    ans=s[i];
                }
                else if(j==i+1){
                    if(s[i]==s[j]){
                        dp[i][j]=1;
                        mx=2;
                        ans=s.substr(i,j-i+1);
                    }
                }
                else{
                    if(s[i]==s[j]){
                        if(dp[i+1][j-1]==1){
                            dp[i][j]=1;
                            if(j-i+1>mx){
                                mx=j-i+1;
                                ans=s.substr(i,j-i+1);
                            }
                        }
                    }
                }
                i++;j++;
            }
        }
        return ans;
    }
};