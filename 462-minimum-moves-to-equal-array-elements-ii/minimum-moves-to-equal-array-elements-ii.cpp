class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<long long> pre(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        vector<long long> post(n);
        post[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--) post[i]=post[i+1]+nums[i];
        long long ans=LLONG_MAX;
        for(int i=0;i<n;i++){
            long long bef=0;
            long long aft=0;
            if(i-1>=0) bef=1.0L*nums[i]*(i)-pre[i-1];
            if(i+1<n) aft=post[i+1]-1.0L*nums[i]*(n-i-1);
            ans=min(ans,aft+bef);
        }
        return ans;
    }
};