class Solution {
public:
    int mncut(int i,int j,vector<int>& tcuts,vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mn=INT_MAX;
        for(int x=i;x<=j;x++){
                int currcost=tcuts[j+1]-tcuts[i-1];
                int leftcost=mncut(i,x-1,tcuts,dp);//now i can't cut at index x again
                int rightcost=mncut(x+1,j,tcuts,dp);
                mn=min(mn,leftcost+rightcost+currcost);
        }
        return dp[i][j]=mn;
    }

    int minCost(int n, vector<int>& cuts) {
        int m=cuts.size();
        sort(cuts.begin(),cuts.end());
       vector<int> tcuts(m+2);
       tcuts[0]=0;
       tcuts[m+1]=n;
       for(int i=1;i<=m;i++) tcuts[i]=cuts[i-1];
       int tsz=tcuts.size();
       vector<vector<int>> dp(tsz,vector<int>(tsz,-1));
       return mncut(1,tsz-2,tcuts,dp);
    }
};