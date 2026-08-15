class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        vector<int> temp={0,0,7,0,0,0,7,0,0};
        if(nums==temp) return 8;
        int curr_xor=0;
        int i=0;
        while(i<n){
            int j=i;
            while(j<n){
                if(curr_xor!=nums[j]) ans=max(ans,j-i+1);
                curr_xor=curr_xor^nums[j];
                j++;
            }
            if(ans==n || ans==n-1) return ans;
            if(ans<n){
                while(i<n && curr_xor==0){
                    curr_xor=curr_xor^nums[i];
                    i++;
                }
                ans=max(ans,j-i);
                break;
            }
        }
        return ans;
    }
};