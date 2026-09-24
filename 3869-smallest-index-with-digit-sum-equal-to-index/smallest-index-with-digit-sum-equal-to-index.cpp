class Solution {
public:
    int f(int n){
        int ans=0;
        while(n>0){
            int l=n%10;
            ans+=l;
            n/=10;
        }
        return ans;
    }

    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(f(nums[i])==i) return i;
        }
        return -1;
    }
};