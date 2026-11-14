class Solution {
public:
    int mnsum(vector<int> &pre,int sz){
        int n=pre.size();
        int ans=pre[sz-1]>0 ? pre[sz-1] : INT_MAX;
        for(int i=sz;i<n;i++){
            int s=pre[i]-pre[i-sz];
            if(s>0) ans=min(ans,s);
        }
        return ans;
    }
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> pre(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        int ans=INT_MAX;
        for(int i=l;i<=r;i++){
            ans=min(ans,mnsum(pre,i));
        }

        return ans==INT_MAX ? -1 : ans;
    }
};