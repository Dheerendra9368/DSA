class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();
        unordered_map<int,int> mp;
        int i=0,j=0;
        while(j<n){
            if(mp[nums[j]]==k){
                ans=max(ans,j-i);
                while(nums[i]!=nums[j]){
                    mp[nums[i]]--;
                    i++;
                }
                mp[nums[i]]--;
                i++;
            }
            mp[nums[j]]++;
            j++;
        }
        ans=max(ans,j-i);
        return ans;
    }
};