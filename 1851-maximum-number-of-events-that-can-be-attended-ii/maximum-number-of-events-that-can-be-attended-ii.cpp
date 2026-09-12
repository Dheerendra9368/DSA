class Solution {
public:
    int correctidx(int i,vector<vector<int>>& events){
        int lo=i+1;
        int hi=events.size()-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(events[mid][0]>events[i][1]) hi=mid-1;
            else lo=mid+1;
        }
        return lo;
    }

    int f(vector<vector<int>>& events,int i,vector<vector<int>> &dp,int k){
        if(i>=events.size() || k>=dp[0].size()) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        int nextidx=correctidx(i,events);
        int take=events[i][2]+f(events,nextidx,dp,k+1);
        int skip=f(events,i+1,dp,k);
        return dp[i][k]=max(take,skip);
    } 

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        int m=events.size();
        vector<vector<int>> dp(m,vector<int>(k,-1));
        return f(events,0,dp,0);          
    }
};