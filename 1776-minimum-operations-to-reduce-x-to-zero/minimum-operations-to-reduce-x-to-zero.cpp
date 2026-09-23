class Solution {
public:

    int fromlast(int target,vector<int> &arr){
        int lo=0;
        int hi=arr.size()-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(arr[mid]==target) return mid;
            else if(arr[mid]<target) lo=mid+1;
            else hi=mid-1;
        }
        return -1;
    }

    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        vector<int> pre(n+1);
        vector<int> post(n+1);
        pre[0]=0;
        for(int i=1;i<=n;i++) pre[i]=pre[i-1]+nums[i-1];
        post[n]=0;
        for(int i=n-1;i>=0;i--) post[i]=post[i+1]+nums[i];
        reverse(post.begin(),post.end());
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int stcnt=i;
            int endcnt=fromlast(x-pre[i],post);
            if(endcnt==-1 || (endcnt+stcnt>n)) continue;
            ans=min(ans,stcnt+endcnt);
        }
        return ans==INT_MAX ? -1 : ans;
    }
};