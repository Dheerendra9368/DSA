class Solution {
public:
    // int mncost(int i,int j,vector<int>& homePos,vector<int>& rowCosts, vector<int>& colCosts,vector<vector<int>> &dp){
    //     if(i==homePos[0] && j==homePos[1]) return 0;
    //     if(dp[i][j]!=INT_MAX) return dp[i][j];
    //     int a=INT_MAX,b=INT_MAX,c=INT_MAX,d=INT_MAX;
    //     if(i+1<rowCosts.size()) a=rowCosts[i+1]+mncost(i+1,j,homePos,rowCosts,colCosts,dp);
    //     if(i-1>=0) b=rowCosts[i-1]+mncost(i-1,j,homePos,rowCosts,colCosts,dp);
    //     if(j+1<colCosts.size()) c=colCosts[j+1]+mncost(i,j+1,homePos,rowCosts,colCosts,dp);
    //     if(j-1>=0) d=colCosts[j-1]+mncost(i,j-1,homePos,rowCosts,colCosts,dp);
    //     return dp[i][j]=min(a,min(b,min(c,d)));
    // }
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        // vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
        // return mncost(startPos[0],startPos[1],homePos,rowCosts,colCosts,dp);
        int ans=0;
        int x1=startPos[0];
        int y1=startPos[1];
        int x2=homePos[0];
        int y2=homePos[1];
        if(x1<x2){
            for(int i=x1+1;i<=x2;i++){
                ans+=rowCosts[i];
            }
        }
        if(x1>x2){
            for(int i=x1-1;i>=x2;i--){
                ans+=rowCosts[i];
            }            
        }
        if(y1<y2){
            for(int i=y1+1;i<=y2;i++){
                ans+=colCosts[i];
            }
        }
        if(y1>y2){
            for(int i=y1-1;i>=y2;i--){
                ans+=colCosts[i];
            }            
        }
        return ans;        
    }
};