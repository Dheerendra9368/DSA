class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        int ans=0;
        while(i<n){
            int j=i+1;
            int k=i;
            while(j<n && nums[j]>nums[k]){
                j++;
                k++;
            }
            ans=max(ans,j-i);
            i=j-1;
            j=i+1;
            k=i;
            while(j<n && nums[j]<nums[k]){
                k++;
                j++;
            }
            ans=max(ans,j-i);
            if(i==j-1) i++;
            else i=j-1;
        }
        return ans;
    }
};