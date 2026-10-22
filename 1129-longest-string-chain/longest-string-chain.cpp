class Solution {
public:

    bool isPredecessor(string s1,string s2){
        // is s1 a predecessor of s2 we have to check
        int n1=s1.size();
        int n2=s2.size();
        if(n2!=(n1+1)) return false;
        int i=0;
        int j=0;
        while(i<n1 && j<n2){
            if(s1[i]!=s2[j]){
                j++;
            }
            else{
                i++;
                j++;
            }
        }
        return i==n1;
    }

    static bool cmp(string s1,string s2){
        return s1.size()<s2.size();
    }

    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),cmp);
        if(n==1) return 1;
        vector<int> dp(n,1);
        int ans=dp[0];
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(isPredecessor(words[j],words[i])){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};