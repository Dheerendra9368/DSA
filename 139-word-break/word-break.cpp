class Solution {
public:
    bool canBe(int i,int j,string &s,unordered_set<string> &st,vector<vector<int>> &dp){
        int n=s.size();
        if(i==n && j==n) return true;
        else if(j==n) return false;

        if(dp[i][j]!=-1) return dp[i][j];

        string str=s.substr(i,j-i+1);
        if(!st.count(str)) return dp[i][j]=canBe(i,j+1,s,st,dp);
        else{
            return dp[i][j]=canBe(j+1,j+1,s,st,dp) || canBe(i,j+1,s,st,dp);
        }
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        unordered_set<string> st;
        for(auto ele:wordDict) st.insert(ele);
        return canBe(0,0,s,st,dp);
    }
};