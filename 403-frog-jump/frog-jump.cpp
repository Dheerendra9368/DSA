class Solution {
public:
   bool cross(int i,int prev,vector<vector<int>> &dp,unordered_map<int,int> &mp,vector<int>& stones){
    if(i>=stones.size() || prev<0) return false;
    if(i==stones.size()-1) return true;
    if(dp[i][prev]!=-1) return dp[i][prev];

    int curr=stones[i];

    int next1=curr+prev-1;
    int next2=curr+prev;
    int next3=curr+prev+1;

    bool opt1,opt2,opt3;
    opt1=opt2=opt3=false;
    if(prev>1 && mp.find(next1)!=mp.end()) opt1=cross(mp[next1],prev-1,dp,mp,stones);
    if(prev>0 && mp.find(next2)!=mp.end()) opt2=cross(mp[next2],prev,dp,mp,stones);
    if(mp.find(next3)!=mp.end()) opt3=cross(mp[next3],prev+1,dp,mp,stones);
    return dp[i][prev]=((opt1 || opt2) || opt3);
   }
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) mp[stones[i]]=i;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        if(stones[1]!=stones[0]+1) return false;
        return cross(1,1,dp,mp,stones);
    }
};