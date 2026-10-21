class Solution {
public:
    int halfmax(int i,vector<int> &arr,int tar,vector<vector<int>> &dp,int &sum){
        if(i<0) return 0;
        if(dp[i][tar]!=-1) return dp[i][tar];
        int pick=0;
        if(tar+arr[i]<=sum/2) pick=arr[i]+halfmax(i-1,arr,tar+arr[i],dp,sum);
        int skip=halfmax(i-1,arr,tar,dp,sum);
        return dp[i][tar]=max(pick,skip);
    }
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        int s=0;
        for(int x:stones) s+=x;      
         vector<vector<int>> dp(n,vector<int>(s/2+1,-1));
       // vector<int> dp(n,-1);
        int x=halfmax(n-1,stones,0,dp,s);//max halfsum u can get
        return s-2*x;
    }
};