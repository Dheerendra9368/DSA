class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int ans=nums[0];
        int n=nums.size();
        int i=1;
        while(i<n && nums[i]==nums[i-1]+1){
            ans+=nums[i];
            i++;
        }
        sort(nums.begin(),nums.end());
        for(int x:nums){
            if(ans==x) ans++;
        }
        return ans;
    }
};