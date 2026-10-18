class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int ans=0;
        int i=0;
        int n=nums.size();
        while(i<n){
            int j=i+1;
            while(j<n && nums[j]==nums[i]) j++;
            ans+=j-i-1;
            i=j;
        }
        return ans;
    }
};