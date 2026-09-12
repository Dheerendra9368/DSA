class Solution {
public:
    int correctidx(int i,vector<vector<int>>& events){
        int lo=i+1;
        int hi=events.size()-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(events[mid][0]>=events[i][1]) hi=mid-1;
            else lo=mid+1;
        }
        return lo;
    }
     
    int f(vector<vector<int>>& events,int i,vector<int> &dp){
        if(i>=events.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int nextidx=correctidx(i,events);
        int take=events[i][2]+f(events,nextidx,dp);
        int skip=f(events,i+1,dp);
        return dp[i]=max(take,skip);
    } 

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<vector<int>> events(n);
        for(int i=0;i<n;i++) events[i]={startTime[i],endTime[i],profit[i]};
        sort(events.begin(),events.end());
        int m=events.size();
        vector<int> dp(m,-1);
        return f(events,0,dp);        
    }
};