class Solution {
public:
    int minMoves(vector<int>& nums) {
        int res=0;
        int mx=0;
        for(int x:nums) mx=max(mx,x);
        for(int x:nums) res+=mx-x;
        return res;
    }
};