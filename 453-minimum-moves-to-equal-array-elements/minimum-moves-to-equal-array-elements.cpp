class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int res=0;
        vector<int> extra(n,0);
        for(int i=1;i<n;i++){
            nums[i]+=extra[i-1];
            int x=nums[i]-nums[i-1];
            extra[i]+=x+extra[i-1];
            res+=x;
        }
        return res;
    }
};