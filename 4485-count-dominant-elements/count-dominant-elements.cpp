class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(i-1<0 && nums[i]>=nums[i+1]) cnt++;
            else if(i+1>=n && nums[i]>=nums[i-1]) cnt++;
            else if(i-1>=0 && i+1<n && 2*nums[i]>=(nums[i-1]+nums[i+1])) cnt++;
        }
        return cnt;
    }
};