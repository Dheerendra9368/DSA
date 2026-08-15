class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int curr_xor=0;
        int cntz=0;
        for(int x:nums){
            curr_xor=curr_xor^x;
            if(x==0) cntz++;
        }
        if(curr_xor==0){
            if(cntz==n) return 0;
            else return n-1;
        }
        else return n;
    }
};