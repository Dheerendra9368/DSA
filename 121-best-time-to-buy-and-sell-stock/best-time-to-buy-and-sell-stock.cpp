class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int buy=INT_MAX; //u will buy with min cost i guesssss....
        for(int x:prices){
            buy=min(buy,x);
            ans=max(ans,x-buy); //if u sell on this curr day the max profit u will get
        }
        return ans;
    }
};