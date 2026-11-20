class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int mx=0;
        for(int x:nums) mx=max(mx,x);
        return k*mx+((k-1)*k)/2;
    }
};