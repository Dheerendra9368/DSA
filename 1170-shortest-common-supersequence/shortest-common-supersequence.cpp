class Solution {
public:
    string lcs(string &s1,string &s2){
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }

        string str="";
        int i=n,j=m;
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                str+=s1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]) i--;
            else j--;
        }
        reverse(str.begin(),str.end());
        return str;

    }
    string shortestCommonSupersequence(string str1, string str2) {
        string str3=lcs(str1,str2);//lcs :))
        cout<<str3;
        int n=str1.size();
        int m=str2.size();
        int p=str3.size();
        int i=0,j=0,k=0;
        string ans="";

        while(i<n && j<m && k<p){

            while(i<n && str1[i]!=str3[k]){
                ans+=str1[i];
                i++;
            }
            while(j<m && str2[j]!=str3[k]){
                ans+=str2[j];
                j++;
            }
                ans+=str3[k];
                k++;
                i++;
                j++;
        }

        while(i<n){
            ans+=str1[i];
            i++;
        }
        while(j<m){
            ans+=str2[j];
            j++;
        }
        return ans;
    }
};