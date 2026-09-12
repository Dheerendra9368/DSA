class Solution {
public:
    int correctidx(int i,vector<vector<int>>& rides){
        int lo=i+1;
        int hi=rides.size()-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(rides[mid][0]>=rides[i][1]) hi=mid-1;
            else lo=mid+1;
        }
        return lo;
    }

    long long f(vector<vector<int>>& rides,int i,vector<long long> &dp){
        if(i>=rides.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int nextidx=correctidx(i,rides);
        long long take=rides[i][1]-rides[i][0]+rides[i][2]+f(rides,nextidx,dp);
        long long skip=f(rides,i+1,dp);
        return dp[i]=max(take,skip);
    }

    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(),rides.end());
        int m=rides.size();
        vector<long long> dp(m,-1);
        return f(rides,0,dp);
    }
};