class Solution {
public:
    int correctidx(int i,vector<vector<int>>& offers){
        int lo=i+1;
        int hi=offers.size()-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(offers[mid][0]>offers[i][1]) hi=mid-1;
            else lo=mid+1;
        }
        return lo;
    }
     
    int f(vector<vector<int>>& offers,int i,vector<int> &dp){
        if(i>=offers.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int nextidx=correctidx(i,offers);
        int take=offers[i][2]+f(offers,nextidx,dp);
        int skip=f(offers,i+1,dp);
        return dp[i]=max(take,skip);
    } 

    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(),offers.end());
        int m=offers.size();
        vector<int> dp(m,-1);
        return f(offers,0,dp);
    }
};