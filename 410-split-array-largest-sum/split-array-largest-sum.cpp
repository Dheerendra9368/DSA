class Solution {
public:
    bool check(vector<int>& nums,int &s,int k){
        int cnt=1;
        int currs=0;
        for(int x:nums){
            if(currs+x<=s){
                currs+=x;
            }
            else{
                currs=x;
                cnt++;
            }
        }
        return cnt<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int lo=0;
        int hi=0;
        for(int x:nums){
            lo=max(lo,x);
            hi+=x;
        }
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(nums,mid,k)){//check if this sum is valid --->means if no of subarrays whose sum is less than equal to mid is atmost k
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};