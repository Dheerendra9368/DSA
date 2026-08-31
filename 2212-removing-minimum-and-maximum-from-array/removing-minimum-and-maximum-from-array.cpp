class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return n;
        int mn=INT_MAX;
        int mnidx=-1;
        int mx=INT_MIN;
        int mxidx=-1;
        for(int i=0;i<n;i++){
            if(mn>nums[i]){
                mn=nums[i];
                mnidx=i;
            }
            if(mx<nums[i]){
                mx=nums[i];
                mxidx=i;
            }
        }

        int m1=max(mnidx+1,mxidx+1);
        int m2=max(n-mnidx,n-mxidx);
        int m3=mnidx+1+n-mxidx;
        int m4=n-mnidx+mxidx+1;
        return min(m1,min(m2,min(m3,m4)));
    }
};