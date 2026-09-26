class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=0) return 0;
        int n=nums.size();
        int l=0;
        int prod=1;
        int cnt=0;
        for(int r=0;r<n;r++){
            prod*=nums[r];
            while(l<=r && prod>=k){
                prod/=nums[l];
                l++;
            }
            cnt+=(r-l+1);
        }
        return cnt;
    }
};